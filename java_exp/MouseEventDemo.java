import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MouseEventDemo {
    public static void main(String[] args) {
        new mouse();
    }
}

class mouse extends JFrame {
    JPanel panel = new JPanel();
    JTextPane txt = new JTextPane();
    String x;
    String y;

    mouse() {
        setSize(200, 200);
        setVisible(true);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        txt.setText("坐标：" + x + y);
        add(panel);
        panel.addMouseMotionListener(new MouseMotionAdapter() {

        });
    }
}
