/*
 * Bitwise Courses - sample Java code
 * http://www.bitwisecourses.com
 */

/**
 *
 * @author huw
 */
public class NewJFrame extends javax.swing.JFrame {

    /** Creates new form NewJFrame */
    public NewJFrame() {
        initComponents();
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        outputTA = new javax.swing.JTextArea();
        testScopeBtn = new javax.swing.JButton();
        scopexBtn = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        outputTA.setColumns(20);
        outputTA.setRows(5);
        jScrollPane1.setViewportView(outputTA);

        testScopeBtn.setText("Scope");
        testScopeBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                testScopeBtnActionPerformed(evt);
            }
        });

        scopexBtn.setText("Scope x");
        scopexBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                scopexBtnActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 499, Short.MAX_VALUE)
                .addContainerGap())
            .addGroup(layout.createSequentialGroup()
                .addComponent(testScopeBtn)
                .addGap(18, 18, 18)
                .addComponent(scopexBtn)
                .addGap(0, 0, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 284, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(testScopeBtn)
                    .addComponent(scopexBtn))
                .addContainerGap(32, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    int x = 10;

    private void aMethod(int x, int anArg) {
        outputTA.append("--- aMethod ---");
        outputTA.append(String.format("\nx = %d, anArg = %d", x, anArg));
    }

    private void anotherMethod(int anArg) {
        outputTA.append("\n--- anotherMethod ---");
        outputTA.append(String.format("\nx = %d, anArg = %d", x, anArg));
    }

    private void yetAnotherMethod() {
        outputTA.append("\n--- yetAnotherMethod ---");
        // outputTA.append(String.format("\nx = %d, anArg = %d", x, anArg ));
        outputTA.append(String.format("\nx = %d", x));
    }

    private void testScopeBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_testScopeBtnActionPerformed
        int x = 100;
        int anArg = 500;
        aMethod(x, anArg);
        anotherMethod(anArg);
        yetAnotherMethod();
        outputTA.append("\n--- testScopeBtnActionPerformed ---");
        outputTA.append(String.format("\nx = %d, anArg = %d", x, anArg));
    }//GEN-LAST:event_testScopeBtnActionPerformed

    private void methodA() {
        // here x has the value 10
        outputTA.append("\n x = " + x);
    }

    private void methodB() {
        int x = 100;
        // here x has the value 100
        outputTA.append("\n x = " + x);
    }

    private void methodC() {
        methodA();
        methodB();
        outputTA.append("\n x = " + x);
    }

    private void scopexBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_scopexBtnActionPerformed
        methodC();
    }//GEN-LAST:event_scopexBtnActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new NewJFrame().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea outputTA;
    private javax.swing.JButton scopexBtn;
    private javax.swing.JButton testScopeBtn;
    // End of variables declaration//GEN-END:variables
}