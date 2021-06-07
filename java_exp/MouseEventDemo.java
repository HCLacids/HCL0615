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
    int x;
    int y;

    mouse() {
        setSize(200, 200);
        setVisible(true);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setBackground(Color.BLUE);
        txt.setText("坐标：" + x + "," + y);
        panel.setBackground(Color.CYAN);
        panel.setBounds(0, 0, 100, 100);
        add(panel);
        panel.add(txt);
        panel.addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e) {
                x = e.getX();
                y = e.getY();
            }
        });
    }
}
