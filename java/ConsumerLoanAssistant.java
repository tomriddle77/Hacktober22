
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ConsumerLoanAssistant extends JFrame implements ActionListener {
    JLabel l1,l2,l3,l4,la;
    JTextField t1,t2,t3,t4;
    JButton b1,b2,x1,x2,exit;
    JTextArea text_area;
    Font flabel,fbutton;
    Boolean t3_enabled=false,t4_enabled=true;

    ConsumerLoanAssistant(){
        super("           Consumer Loan Assistant");

        text_area=new JTextArea("");
        text_area.setBounds(400,40,300,150);
        text_area.setFont(new Font("Arial",Font.PLAIN,14));

        text_area.setForeground(Color.BLACK);
        text_area.setEditable(false);
        text_area.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        add(text_area);

        flabel =new Font("Arial", Font.PLAIN,16);
        fbutton=new Font("SANS_SERIF",Font.BOLD,13);

        la = new JLabel("Loan Analysis: ");
        l1=new JLabel("Loan Balance");
        l2=new JLabel("Interest Rate");
        l3=new JLabel("Number of Payments");
        l4=new JLabel("Monthly Payment");

        t1=new JTextField();
        t2=new JTextField();
        t3=new JTextField();
        t4=new JTextField();

        b1=new JButton("Compute Monthly Payment");
        b2=new JButton("New Loan Analysis");

        setLayout(null);
        setSize(800,300);

        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        la.setBounds(400,0,150,50);
        la.setFont(flabel);
        add(la);

        l1.setBounds(20,0,100,50);
        l1.setFont(flabel);
        add(l1);

        l2.setBounds(20,30,150,50);
        l2.setFont(flabel);
        add(l2);

        l3.setBounds(20,60,150,50);
        l3.setFont(flabel);
        add(l3);

        l4.setBounds(20,90,150,50);
        l4.setFont(flabel);
        add(l4);

        b1.setBounds(50,140,250,30);
        b1.setFont(fbutton);
        add(b1);

        b2.setBounds(75,190,200,30);
        b2.setFont(fbutton);
        b2.setEnabled(false);
        add(b2);

        b1.addActionListener(this);
        b2.addActionListener(this);

        t1.setBounds(170,15,100,20);
        t1.setFont(flabel);
        t1.setHorizontalAlignment(JTextField.RIGHT);
        add(t1);

        t2.setBounds(170,45,100,20);
        t2.setHorizontalAlignment(JTextField.RIGHT);
        t2.setFont(flabel);
        add(t2);

        t3.setBounds(170,80,100,20);
        t3.setHorizontalAlignment(JTextField.RIGHT);
        t3.setFont(flabel);
        add(t3);

        t4.setBounds(170,110,100,20);
        t4.setHorizontalAlignment(JTextField.RIGHT);
        t4.setFont(flabel);
        t4.setEditable(false);
        t4.setForeground(Color.BLACK);
        t4.setBackground(Color.YELLOW.brighter());
        add(t4);

        x1=new JButton("X");
        x1.setBounds(300,70,50,25);
        x1.setFont(fbutton);
        add(x1);

        x2=new JButton("X");
        x2.setBounds(300,110,50,25);
        x2.setFont(fbutton);
        add(x2);
        x2.setVisible(false);

        x1.addActionListener(this);
        x2.addActionListener(this);

        exit= new JButton("Exit");
        exit.setBounds(500,220,100,30);
        exit.setFont(fbutton);
        add(exit);
        exit.addActionListener(this);


    }

    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==b1) {
            try {
                if(t2.getText().equals("") || t2.getText().equals("0")) {
                JOptionPane.showMessageDialog(null,"Invalid or empty Interest Rate entry.\nPlease correct.");
                }
                if ((t1.getText().equals("") || t2.getText().equals("") || t3.getText().equals("")) && (t1.getText().equals("") || t2.getText().equals("") || t4.getText().equals(""))) {
                    JOptionPane.showMessageDialog(null, "Fill All The Required Details");
                }
                if (t4.getText().equals("")) {
                    float A = Float.parseFloat(t1.getText());
                    float i = Float.parseFloat(t2.getText());
                    float n = Float.parseFloat(t3.getText());
                    float I = i / 1200;
                    float P = (float) (I * A / (1 - Math.pow((1 + I), -n)));
                    t4.setText(P + "");
                    String str="Loan Amount : $"+A+"\n";
                    str+="Interest Rate : "+I*1200+"%\n\n";
                    str+=n+" Payments of : $"+P;
                    text_area.setText(str);
                }
                if (t3.getText().equals("")) {
                    float A = Float.parseFloat(t1.getText());
                    float i = Float.parseFloat(t2.getText());
                    float P = Float.parseFloat(t4.getText());
                    float I = i / 1200;
                    float n = (float) (-(Math.log10(1 - I * A / P)) / Math.log10(1 + I));
                    t3.setText(n + "");
                    String str="Loan Amount : $"+A+"\n";
                    str+="Interest Rate : "+I*1200+"%\n\n";
                    str+=n+" Payments of : $"+P;
                    text_area.setText(str);
                }

                b1.setEnabled(false);
                b2.setEnabled(true);
            }catch (Exception ex){
                System.out.println(ex);
            }
        }
        if(e.getSource()==b2) {
            if (t4_enabled) {
                t4.setText(null);

            }
            if(t3_enabled){
                t3.setText(null);
            }
            b1.setEnabled(true);
            b2.setEnabled(false);
        }
        if(e.getSource()==x1){
            x1.setVisible(false);
            x2.setVisible(true);
            t4.setEditable(true);
            t3.setEditable(false);
            t3.setBackground(Color.YELLOW.brighter());
            t4.setBackground(Color.white);
            t3_enabled=true;
            t4_enabled=false;
            t3.setText(null);

            b1.setEnabled(true);
            b2.setEnabled(false);
        }
        if(e.getSource()==x2){
            x1.setVisible(true);
            x2.setVisible(false);
            t4.setEditable(false);
            t3.setEditable(true);
            t3.setBackground(Color.white);
            t4.setBackground(Color.YELLOW.brighter());
            t3_enabled=false;
            t4_enabled=true;
            t4.setText(null);

            b1.setEnabled(true);
            b2.setEnabled(false);
        }
        if(e.getSource()==exit){
            System.exit(0);
        }
    }
    public static void main(String[] args) {
       
         new ConsumerLoanAssistant();
    }

}
