import java.awt.*;
import javax.swing.*;
import javax.swing.plaf.DimensionUIResource;

import org.graalvm.compiler.graph.Graph;

public class JButtonDemo {
    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            SimpleFrame frame = new SimpleFrame();
            JButton button = new JButton("按钮1");
            button.setPreferredSize(new Dimension(10, 10));
            frame.add(button);
            frame.setBounds(0, 0, 400, 300);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
        });
    }
}

class SimpleFrame extends JFrame {
    private static final int DEFAULT_WIDTH = 400;
    private static final int DEFAULT_HEIGHT = 500;
    private static final String DEFAULT_TITLE = "测试按钮类";

    public SimpleFrame() {
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
        setTitle(DEFAULT_TITLE);
    }
}

class MyComponent extends JComponent {
    public static final int MESSAGE_X = 75;
    public static final int MESSAGE_Y = 100;
    public static final int DEFAULT_WIDTH = 300;
    public static final int DEFALT_HEIGHT = 200;

    public void paintComponent(Graphics g) {
        g.drawString("hello ", MESSAGE_X, MESSAGE_Y);
    }

    public Dimension getPreferredDimension() {
        return new Dimension(DEFAULT_WIDTH, DEFALT_HEIGHT);
    }
}