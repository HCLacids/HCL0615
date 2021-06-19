import java.awt.*;

import javax.swing.*;

public class GUIExample {
    public static void main(String[] args) {
        new GUI();
    }
}

class GUI extends JFrame {
    JRadioButton ages[] = new JRadioButton[5];
    JCheckBox hobby[] = new JCheckBox[5];
    JTextPane txt = new JTextPane();
    ButtonGroup g = new ButtonGroup();
    JButton button = new JButton("提交");

    GUI() {
        int index = 0;
        setBounds(10, 10, 460, 360);
        setLayout(new FlowLayout());
        for (int i = 0; i < 5; i++) {
            ages[i] = new JRadioButton(i + 5 + "-" + (i + 15));
            ages[i].addActionListener(event -> {

            });
            add(ages[i]);
            g.add(ages[i]);
        }
        for (int i = 0; i < 5; i++) {
            hobby[i] = new JCheckBox(i + "");
            hobby[i].addActionListener(event -> {

            });
            add(hobby[i]);
        }
        button.addActionListener(event -> {
            txt.setText("");
            add(txt);
        });
        add(button);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}