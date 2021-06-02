import java.awt.*;
import javax.swing.*;

public class JButtonDemo {
    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            SimpleFrame frame = new SimpleFrame();
            JButton button = new JButton("按钮1");
            JButton button2 = new JButton("按钮2");
            frame.add(button);
            frame.add(button2);
            frame.setBounds(0, 0, 400, 300);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
            JTextField txt = new JTextField(20);
            frame.add(txt);
            button.addActionListener(event -> {
                txt.setText("button1");
            });
            button2.addActionListener(event -> {
                txt.setText("button2");
            });
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
