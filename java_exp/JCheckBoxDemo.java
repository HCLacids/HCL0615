import javax.swing.*;
import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Font;

public class JCheckBoxDemo {
    public static void main(String[] args) {
        new Jf();
    }
}

class Jf extends JFrame implements ActionListener {
    JTextPane text = new JTextPane();

    Jf() {
        setSize(200, 200);
        setVisible(true);
        setLayout(new FlowLayout());
        text.setText("注意字体变化");
        JCheckBox box1 = new JCheckBox("粗体");
        JCheckBox box2 = new JCheckBox("斜体");
        box1.addActionListener(event -> {
            Font font = new Font("Serif", Font.BOLD, 18);
            text.setFont(font);
        });
        box2.addActionListener(event -> {
            Font font = new Font("Serif", Font.ITALIC, 18);
            text.setFont(font);
        });
        add(text);
        add(box1);
        add(box2);
        validate();
        setDefaultCloseOperation(EXIT_ON_CLOSE);

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub

    }
}
