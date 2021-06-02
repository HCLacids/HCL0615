import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ColorDialogDemo {
    public static void main(String arugs[]) {
        new Jfss();
    }
}

class Jfss extends JFrame implements ActionListener {
    JButton button = new JButton("显示窗口");
    JColorChooser color = new JColorChooser();
    Color c;

    Jfss() {
        setSize(200, 200);
        setVisible(true);
        setLayout(new FlowLayout());
        add(button);
        button.addActionListener(event -> {
            c = color.showDialog(null, "", null);
            setBackground(c);
        });
        validate();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub

    }

}
