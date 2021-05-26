import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class JRadioDemo extends JFrame{
    private JPanel buttonPanel;
    private static final int DEFAULT_WIDTH = 300;
    private static final int DEFAULT_HEIGHT = 200;

    public JRadioDemo() {
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    }
    public static class ColorAction implements ActionListener {
        private Color color;
        public ColorAction(Color color) {
            color = color;
        }
        public void actionPerformed(ActionEvent e){
            // frame.setBackground(color);
        }
    }
    public static void main(String[] args){
        EventQueue.invokeLater(() -> {
            SimpleFrame frame = new SimpleFrame();
            JRadioDemo button = new JRadioDemo();
            JRadioButton red = new JRadioButton("Red");
            JRadioButton green = new JRadioButton("Green");
            JRadioButton blue = new JRadioButton("Blue");

            ColorAction r = new ColorAction(Color.RED);
            ColorAction g = new ColorAction(Color.GREEN);
            ColorAction b = new ColorAction(Color.BLUE);

            red.addActionListener(r);
            green.addActionListener(g);
            blue.addActionListener(b);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
            frame.add(red);
            frame.add(green);
            frame.add(blue);
        });
    }
}

class SimpleFrame extends JFrame {
    private static final int DEFAULT_WIDTH = 300;
    private static final int DEFAULT_HEIGHT = 200;
    private static final String DEFAULT_TITLE = "测试按钮类";

    public SimpleFrame() {
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
        setTitle(DEFAULT_TITLE);
        validate();
        setLayout(new FlowLayout());
    }
}

