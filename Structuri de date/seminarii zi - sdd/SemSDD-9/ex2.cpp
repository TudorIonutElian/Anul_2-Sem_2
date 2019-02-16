#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

const int KeyFieldMax = 12;

const int KFMaxPlus1 = KeyFieldMax + 1;

const int DataFieldMax = 36;

const int DFMaxPlus1 = DataFieldMax + 1;

typedef char KeyFieldType[KFMaxPlus1];

typedef char DataFieldType[DFMaxPlus1];

typedef struct
   {
   KeyFieldType KeyField;
   DataFieldType DataField;
   } ItemType;

class TableBaseClass
   {
   public:
      virtual bool Empty(void) = 0;
      virtual bool Insert(const ItemType & Item) = 0;
      virtual bool Retrieve(KeyFieldType SearchKey, ItemType & Item) = 0;
   protected:
      fstream DataFile;   // the file stream for the table data
      long NumItems;      // number of records in the table
      char OpenMode;      // r or w (read or write) mode for the table
   };

// comment off the following line if you want to omit debugging output:
#define DEBUG

const int MaxKeys = 11;   // max number of keys in a node

const int MaxKeysPlusOne = MaxKeys + 1;

const int MinKeys = 5;    // min number of keys in a node

const long NilPtr = -1L;   // the L indicates a long int

typedef struct
   {
   int Count;               // Number of keys stored in the current node
   ItemType Key[MaxKeys];   // Warning: indexing starts at 0, not 1
   long Branch[MaxKeysPlusOne];   // Fake pointers to child nodes
   } NodeType;

void Error(char * msg);

class BTTableClass: public TableBaseClass
   {
   public:
      BTTableClass(char Mode, char * FileName);
      ~BTTableClass(void);
      bool Empty(void);
      bool Insert(const ItemType & Item);
      bool Retrieve(KeyFieldType SearchKey, ItemType & Item);
      void Dump(void);   // for debugging only - could be removed
      void Check(void);   // for debugging only
   private:
      void CheckSubtree(long Current, KeyFieldType & Last); // for debugging
      bool SearchNode(const KeyFieldType Target, int & location) const;
      void AddItem(const ItemType & NewItem, long NewRight,
         NodeType & Node, int Location);
      void Split(const ItemType & CurrentItem, long CurrentRight,
         long CurrentRoot, int Location, ItemType & NewItem,
         long & NewRight);
      void PushDown(const ItemType & CurrentItem, long CurrentRoot,
         bool & MoveUp, ItemType & NewItem, long & NewRight);
      long Root;       // fake pointer to the root node
      long NumNodes;   // number of nodes in the B-tree
      int NodeSize;    // number of bytes per node
      NodeType CurrentNode;   // storage for current node being worked on
   };

/* Given:  msg   A message.
   Task:   To print msg and exit the program.
   Return: Nothing to the program, of course, but returns 1 to the
           operating system.
*/

void Error(char * msg)
   {
   cerr << msg << endl;
   exit(1);
   }

/* Given:   Nothing (other than the implicit BTTableClass object)
   Task:    To print out all info associated with the current table.
            Note that this is for debugging purposes.  This function
            could be removed once debugging is complete.
   Return:  Nothing.
*/

void BTTableClass::Dump(void)
   {
   int k;
   long p;

   cout << endl << "Root is node (record) number " << Root << endl;

   for (p = 0; p <= NumNodes; p++)
      {
      if (p % 4 == 3)
         {
         cout << " Press ENTER";
         cin.get();
         }

      DataFile.seekg(p * NodeSize, ios::beg);
      DataFile.read(reinterpret_cast <char *> (&CurrentNode), NodeSize);

      if (p == 0)
         {
         cout << "Node 0 is not part of tree, contains this data:" << endl;
         cout << "   NumItems = " << CurrentNode.Branch[0] << endl;
         cout << "   NumNodes = " << CurrentNode.Branch[1] << endl;
         cout << "   Root = " << CurrentNode.Branch[2] << endl;
         }
      else
         {
         cout << "Dump of node number " << p << endl;
         cout << "   Count: " << CurrentNode.Count << endl;

         cout << "   Keys: ";
         for (k = 0; k < CurrentNode.Count; k++)
            cout << CurrentNode.Key[k].KeyField << " ";

         cout << endl << "   Branches: ";
         for (k = 0; k <= CurrentNode.Count; k++)
            cout << CurrentNode.Branch[k] << " ";
         cout << endl << endl;
         }
      }
   }

/* Given:   Nothing (other than the implicit BTTableClass object)
   Task:    To do an inorder traversal of the B-Tree looking for out of
            order items.
            Note that this is for debugging purposes.  This function
            could be removed once debugging is complete.
   Return:  Nothing.
*/

void BTTableClass::Check(void)
   {
   KeyFieldType Last;

   Last[0] = '*';
   Last[1] = NULL;
   CheckSubtree(Root, Last);
   }

/* Given:   The implicit BTTableClass object plus:
            Current   A pseudopointer to the root node of the subtree.
            Last      The Last key field value that was checked.
   Task:    To do an inorder traversal of the subtree rooted at the
            current node.  Each key field value is checked against Last
            to see if it is out of order relative to Last.  If so,
            debugging info is printed, including a complete dump of
            the B-tree.
            Note that this is for debugging purposes.  This function
            could be removed once debugging is complete.
   Return:  Nothing.
*/

void BTTableClass::CheckSubtree(long Current, KeyFieldType & Last)
   {
   NodeType Node;
   int k;

   if (Current == NilPtr)
      return;

   DataFile.seekg(Current * NodeSize, ios::beg);
   DataFile.read(reinterpret_cast <char *> (&Node), NodeSize);
   for (k = 0; k < Node.Count; k++)
      {
      CheckSubtree(Node.Branch[k], Last);
      if ((Last[0] != '*') && (strcmp(Last, Node.Key[k].KeyField) >= 0))
         {
         cout << "Check has found a problem in node " << Current <<
            " index " << k << " key " << Node.Key[k].KeyField << endl;
         Dump();
         exit(1);
         }
      strcpy(Last, Node.Key[k].KeyField);
      }
   CheckSubtree(Node.Branch[Node.Count], Last);
   }

/* Given:   Mode      A char(r or w) to indicate read or write mode.
            FileName  A char string holding the external filename.
   Task:    This is the constructor for a BTTableClass object.  If mode
            r is specified, it opens the table stored in the given file
            for reading.  If w is specified, it opens a new, empty table
            for writing (to the given file).  A new empty table contains
            a "dummy" node (node zero) that will be used to hold info
            about the whole table.
   Return:  Nothing directly, but the implicit object is created.
*/

BTTableClass::BTTableClass(char Mode, char * FileName)
   {
   #ifdef DEBUG
      cout << "BTTableClass constructor called" << endl;
   #endif

   OpenMode = Mode;
   NodeSize = sizeof(NodeType);

   if (Mode == 'r')
      {
      DataFile.open(FileName, ios::in | ios::binary);
      if (DataFile.fail())
         Error("File cannot be opened");

      DataFile.read(reinterpret_cast <char *> (&CurrentNode), NodeSize);
      if (DataFile.fail())
         {   // assume the Btree is empty if you cannot read from the file
         NumItems = 0;
         NumNodes = 0;
         Root = NilPtr;
         }
      else   // Node zero is not a normal node, it contains the following:
         {
         NumItems = CurrentNode.Branch[0];
         NumNodes = CurrentNode.Branch[1];
         Root = CurrentNode.Branch[2];
         }
      #ifdef DEBUG
         cout << "R";
      #endif
      }
   else if (Mode == 'w')
      {
      DataFile.open(FileName, ios::in | ios::out | ios:: trunc |
         ios::binary);
      if (DataFile.fail())
         Error("File cannot be opened");

      Root = NilPtr;
      NumItems = 0;
      NumNodes = 0;   // number does not include the special node zero
      CurrentNode.Branch[0] = NumItems;
      CurrentNode.Branch[1] = NumNodes;
      CurrentNode.Branch[2] = Root;
      DataFile.seekp(0, ios::beg);
      DataFile.write(reinterpret_cast <char *> (&CurrentNode), NodeSize);

      #ifdef DEBUG
         cout << "W";
      #endif
      }
   else
      Error("Incorrect mode given to BTTableClass constructor");
   }

/* Given:   Nothing (other than the implicit object).
   Task:    This is the destructor for a BTTableClass object.  Its job
            is to destroy the BTTableClass object, while making sure that
            all of the table data is stored in the associated file.
   Return:  Nothing directly, but the file is updated.
*/

BTTableClass::~BTTableClass(void)
   {
   #ifdef DEBUG
      cout << endl << "BTTableClass destructor called" << endl;
   #endif

   if (OpenMode == 'w')
      {
      //  Be sure to write out the updated node zero:
      CurrentNode.Branch[0] = NumItems;
      CurrentNode.Branch[1] = NumNodes;
      CurrentNode.Branch[2] = Root;
      DataFile.seekp(0, ios::beg);
      DataFile.write(reinterpret_cast <char *> (&CurrentNode), NodeSize);

      #ifdef DEBUG
         cout << "W";
      #endif
      }

   #ifdef DEBUG
      Dump();
   #endif

   DataFile.close();
}

/* Given:   Nothing (other than the implicit object).
   Task:    To decide if the implicit table object is empty.
   Return:  In the function name, true if the table object is empty,
            false otherwise.
*/

bool BTTableClass::Empty(void)
   {   // we could read node zero, but this is faster:
   return (Root == NilPtr);
   }

/* Given:   The implicit BTTableClass object as well as:
            Target        The value to look for in the CurrentNode field.
   Task:    To look for Target as a key in CurrentNode.
   Return:  In the function name, return true if found, false otherwise.
            Location      The index of where Target was found.  If not
                          found, index and index + 1 are the indices between
                          which Target would fit.  (If Target fits to the
                          left of the first key, returns index of -1.)
*/

bool BTTableClass::SearchNode(const KeyFieldType Target,
   int & Location) const
   {
   bool Found;

   Found = false;
   if (strcmp(Target, CurrentNode.Key[0].KeyField) < 0)
      Location = -1;
   else
      { // do a sequential search, right to left:
      Location = CurrentNode.Count - 1;
      while ((strcmp(Target, CurrentNode.Key[Location].KeyField) < 0)
         && (Location > 0))
         Location--;

      if (strcmp(Target, CurrentNode.Key[Location].KeyField) == 0)
         Found = true;
      }

   return Found;
}

/* Given:   The implicit BTTableClass object as well as:
            NewItem       Item to add to Node.
            NewRight      Pseudopointer to right subtree below NewItem.
            Node          The node to be added to.
            Location      The index at which to add newItem.
   Task:    To add Item to Node at index Location, and add NewRight
            as the branch just to the right of NewItem.  The addition is
            made by moving the needed keys and branches right by 1 in order
            to clear out index Location for NewItem.
   Return:  Node          Updated node.
*/

void BTTableClass::AddItem(const ItemType & NewItem, long NewRight,
   NodeType & Node, int Location)
   {
   int j;

   for (j = Node.Count; j > Location; j--)
      {
      Node.Key[j] = Node.Key[j - 1];
      Node.Branch[j + 1] = Node.Branch[j];
      }

   Node.Key[Location] = NewItem;
   Node.Branch[Location + 1] = NewRight;
   Node.Count++;
}

/* Given: The implicit BTTableClass object as well as:
          CurrentItem    Item whose attempted placement into a node is
                         causing the node to be split.
          CurrentRight   Pseudopointer to the child just to the right of
                         CurrentItem.
          CurrentRoot    Pseudopointer to the node to be split.
          Location       Index of where CurrentItem should go in this node.
  Task:   To split the node that CurrentRoot points to into 2 nodes,
          pointed to by CurrentRoot and NewRight.  CurrentItem is properly
          placed in 1 of these 2 nodes (unless it is the median that gets
          moved up to the parent).  Finds Newitem, the median item that is
          to be moved up to the parent node.
  Return: NewItem        The item to be moved up into the parent node.
          NewRight       The pseudopointer to the child to the right of
                         NewItem (i.e. a pointer to the new RightNode).
*/

void BTTableClass::Split(const ItemType & CurrentItem, long CurrentRight,
   long CurrentRoot, int Location, ItemType & NewItem, long & NewRight)
   {
   int j, Median;
   NodeType RightNode;

   #ifdef DEBUG
      cout << "S";
   #endif

   if (Location < MinKeys)
      Median = MinKeys;
   else
      Median = MinKeys + 1;

   DataFile.seekg(CurrentRoot * NodeSize, ios::beg);
   DataFile.read(reinterpret_cast <char *> (&CurrentNode), NodeSize);

   #ifdef DEBUG
      cout << "R";
   #endif

   for (j = Median; j < MaxKeys; j++)
      {  // move half of the items to the RightNode
      RightNode.Key[j - Median] = CurrentNode.Key[j];
      RightNode.Branch[j - Median + 1] = CurrentNode.Branch[j + 1];
      }

   RightNode.Count = MaxKeys - Median;
   CurrentNode.Count = Median;   // is then incremented by AddItem

   // put CurrentItem in place
   if (Location < MinKeys)
      AddItem(CurrentItem, CurrentRight, CurrentNode, Location + 1);
   else
      AddItem(CurrentItem, CurrentRight, RightNode,
         Location - Median + 1);

   NewItem = CurrentNode.Key[CurrentNode.Count - 1];
   RightNode.Branch[0] = CurrentNode.Branch[CurrentNode.Count];
   CurrentNode.Count--;

   DataFile.seekp(CurrentRoot * NodeSize, ios::beg);
   DataFile.write(reinterpret_cast <char *> (&CurrentNode), NodeSize);

   #ifdef DEBUG
      cout << "W";
   #endif

   NumNodes++;
   NewRight = NumNodes;
   DataFile.seekp(NewRight * NodeSize, ios::beg);
   DataFile.write(reinterpret_cast <char *> (&RightNode), NodeSize);

   #ifdef DEBUG
      cout << "W";
   #endif
   }

/* Given:  The implicit BTTableClass object as well as:
           CurrentItem   The item to be inserted into the B-tree table.
           CurrentRoot   Pseudopointer to root of current subtree.
   Task:   To find where to put CurrentItem in a node of the subtree with
           the given root.  CurrentItem is ordinarily inserted, though
           a duplicate item is refused.  It is also possible that
           CurrentItem might be the item moved up to be inserted into
           the parent node if a split is done.
   Return: MoveUp        True if NewItem (and associated NewRight pointer)
                         must be placed in the parent node due to
                         splitting, false otherwise.
           NewItem       Item to be placed into parent node if a split was
                         done.
           NewRight      Pseudopointer to child to the right of NewItem.
*/

void BTTableClass::PushDown(const ItemType & CurrentItem, long CurrentRoot,
   bool & MoveUp, ItemType & NewItem, long & NewRight)
   {
   int Location;

   #ifdef DEBUG
      cout << "P";
   #endif

   if (CurrentRoot == NilPtr)   // stopping case
      {   // cannot insert into empty tree
      MoveUp = true;
      NewItem = CurrentItem;
      NewRight = NilPtr;
      }
   else   // recursive case
      {
      DataFile.seekg(CurrentRoot * NodeSize, ios::beg);
      DataFile.read(reinterpret_cast <char *> (&CurrentNode), NodeSize);

      #ifdef DEBUG
         cout << "R";
      #endif

      if (SearchNode(CurrentItem.KeyField, Location))
         Error("Error: attempt to put a duplicate into B-tree");

      PushDown(CurrentItem, CurrentNode.Branch[Location + 1], MoveUp,
         NewItem, NewRight);

      if (MoveUp)
         {
         DataFile.seekg(CurrentRoot * NodeSize, ios::beg);
         DataFile.read(reinterpret_cast <char *> (&CurrentNode), NodeSize);

         #ifdef DEBUG
            cout << "R";
         #endif

         if (CurrentNode.Count < MaxKeys)
            {
            MoveUp = false;
            AddItem(NewItem, NewRight, CurrentNode, Location + 1);
            DataFile.seekp(CurrentRoot * NodeSize, ios::beg);
            DataFile.write(reinterpret_cast <char *> (&CurrentNode),
               NodeSize);

            #ifdef DEBUG
               cout << "W";
            #endif
            }
         else
            {
            MoveUp = true;
            Split(NewItem, NewRight, CurrentRoot, Location,
               NewItem, NewRight);
            }
         }
      }
   }


/* Given:   The implicit BTTableClass object as well as:
            Item       Item to add to the table.
   Task:    To add Item to the table.
   Return:  In the function name, returns true to indicate success.
            (The implicit object is modified, of course.)
*/

bool BTTableClass::Insert(const ItemType & Item)
   {
   bool MoveUp;
   long NewRight;
   ItemType NewItem;

   #ifdef DEBUG
      cout << "I";
   #endif

   PushDown(Item, Root, MoveUp, NewItem, NewRight);

   if (MoveUp)   // create a new root node
      {
      CurrentNode.Count = 1;
      CurrentNode.Key[0] = NewItem;
      CurrentNode.Branch[0] = Root;
      CurrentNode.Branch[1] = NewRight;
      NumNodes++;
      Root = NumNodes;
      DataFile.seekp(NumNodes * NodeSize, ios::beg);
      DataFile.write(reinterpret_cast <char *> (&CurrentNode), NodeSize);

      #ifdef DEBUG
         cout << "W";
      #endif
      }

   NumItems++;   
   return true;   // no reason not to assume success
}

/* Given:   The implicit BTTableClass object as well as:
            SearchKey   Key value to look for in the table.
   Task:    To look for SearchKey in the table.
   Return:  In the function name, true if SearchKey was found,
            false otherwise.
            Item        The item were SearchKey was found.
*/

bool BTTableClass::Retrieve(KeyFieldType SearchKey, ItemType & Item)
   {
   long CurrentRoot;
   int Location;
   bool Found;

   Found = false;
   CurrentRoot = Root;

   while ((CurrentRoot != NilPtr) && (! Found))
      {
      DataFile.seekg(CurrentRoot * NodeSize, ios::beg);
      DataFile.read(reinterpret_cast <char *> (&CurrentNode), NodeSize);

      #ifdef DEBUG
         cout << "R";
      #endif

      if (SearchNode(SearchKey, Location))
         {
         Found = true;
         Item = CurrentNode.Key[Location];
         }
      else
         CurrentRoot = CurrentNode.Branch[Location + 1];
      }

   return Found;
}

const int LineMax = KeyFieldMax + DFMaxPlus1;

typedef char StringType[LineMax];


/* Given:  InStream     An input file stream open for reading.
           StringMax    The maximum number of characters that can be put
                        into String, including the NULL that marks the end
                        of the string.
   Task:   To read up to StringMax - 1 characters from InStream, storing
           them in String, but stopping if a newline is read or end of
           file or an error condition is reached.
   Return: String       The string just read, with a NULL appended to mark
                        the end of the string.  If a newline was read, it
                        is not stored in String.
           The number of characters read into String (not counting the NULL)    
           is returned in the function name.
*/

int MyGetLine(istream & InStream, char * String, int StringMax)
   {
   char Ch;
   int Count, Last;

   Count = 0;
   Last = StringMax - 1;
   Ch = InStream.get();

   while ((Ch != '\n') && (! InStream.fail()))
      {
      if (Count < Last)
         String[Count++] = Ch;
      Ch = InStream.get();
      }

   String[Count] = NULL;
   return Count;
   }

/* Given:  InputFile   A file stream already opened for input on a text file.
   Task:   To read in a Word and its Definition from one line of this file.
   Return: Word        In char array form, the word read in.
           Definition  In char array form, the definition read in.
*/

void ReadLine(fstream & InputFile, KeyFieldType Word,
   DataFieldType Definition)
   {
   char Line[LineMax];
   int k, ch;

   MyGetLine(InputFile, Line, LineMax);   // will read the newline char

   for (k = 0; k < KeyFieldMax; k++)
      Word[k] = Line[k];
   Word[KeyFieldMax] = NULL;

   for (k = 0; k < DataFieldMax; k++)
      {
      ch = Line[KeyFieldMax + k];
      if (ch == '\n')
         break;
      Definition[k] = ch;
      }
   Definition[k] = NULL;
  }

/* Given:  InputFile   A file stream already opened for input.
   Task:   To read the data from InputFile and load it into the Table.
   Return: Table       The B-tree table containing the data.
*/

void Load(fstream & InputFile, BTTableClass & Table)
   {
   ItemType Item;
   int Count;

   Count = 0;
   ReadLine(InputFile, Item.KeyField, Item.DataField);

   while (! InputFile.fail())
      {
      #ifdef DEBUG
         Count++;
         if (Count == 22)
            {
            Count = 0;
            cout << endl << "Press ENTER";
            cin.get();
            }
         cout << endl << "DEBUG: ready to insert " << Item.KeyField << " ";
      #endif

      Table.Insert(Item);

      #ifdef DEBUG
         Table.Check();
      #endif

      ReadLine(InputFile, Item.KeyField, Item.DataField);
      }
   }

/* Given:  Nothing.
   Task:   To read in one word from the keyboard (or . to signal desire
           to quit).
   Return: Word   In char array form, the word read in, capitalized and
                  padded on the right with blanks so that it contains 12
                  characters.
           In the function name, return true if a word was read in, false
           if a . was read in.
*/

bool ReadKeyboard(KeyFieldType Word)
   {
   int k, ch;
   bool start;

   cin >> Word;
   cin.get();   // get the newline

   if (Word[0] == '.')
      return false;

   start = true;

   for (k = 0; k < KeyFieldMax; k++)
      {
      ch = Word[k];
      if (ch == NULL)
         start = false;
      if (start)
         Word[k] = toupper(ch);   // capitalize
      else
         Word[k] = ' ';   // pad with blanks
      }

   Word[KeyFieldMax] = NULL;
   return true;
   }


void main()
{
   ItemType Item;
   KeyFieldType SearchKey;
  /* BTTableClass BTTable1('r', "btree.txt");

   if (BTTable1.Empty())
      Error("Table is empty");

   cout << "Enter the word to be looked up (or . to quit): ";

   while (ReadKeyboard(SearchKey))
      {
      if (BTTable1.Retrieve(SearchKey, Item))
         cout << " Definition:   " << Item.DataField << endl;
      else
         cout << " Not found" << endl;
      cout << endl << "Enter the word to be looked up (or . to quit): ";
      }*/
   
   fstream Source;
   BTTableClass BTTable2('w', "results.txt");

   Source.open("btree.txt", ios::in);
   if (Source.fail())
      {
      cerr << "ERROR: Unable to open file btree.txt" << endl;
      exit(1);
      }

   Load(Source, BTTable2);
   Source.close();

   getch();

}

