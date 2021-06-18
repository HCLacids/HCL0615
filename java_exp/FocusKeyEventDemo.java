import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class FocusKeyEventDemo {
    public static void main(String[] args) {
        new KeyFrame("test");
    }
}

class KeyFrame extends JFrame {
    JTextField text[] = new JTextField[3]; // 创建三个文本框
    Police police; // 监视器
    JButton b;
    JTextPane txt = new JTextPane();

    KeyFrame(String s) {
        setTitle(s);
        setBounds(10, 10, 460, 360);
        setLayout(new FlowLayout());
        police = new Police();
        for (int i = 0; i < 3; i++) {
            text[i] = new JTextField(7);
            text[i].addKeyListener(police); // 给文本框添加键盘监听器
            text[i].addFocusListener(police); // 给文本框添加焦点监听器
            add(text[i]);
        }
        b = new JButton("确定");
        add(b);
        add(txt);
        b.addActionListener(event -> {
            if (event.getSource() == b) {
                txt.setText("序列号:" + text[0].getText() + text[1].getText() + text[2].getText());
            }
        });
        text[0].requestFocusInWindow(); // 初始状态先让第一个文本框获得焦点
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public class Police implements KeyListener, FocusListener {
        // 实现键盘监听器接口
        // 键盘按下函数
        public void keyPressed(KeyEvent e) {
            JTextField t = (JTextField) e.getSource();
            if (t.getCaretPosition() >= 5) // 如果焦点大于等于6(从0开始)的时候，每按一下键盘都进行一次判断
            {
                t.transferFocus(); // 焦点转移到下一个组件
            }

        }

        // 键盘按下释放函数
        public void keyTyped(KeyEvent e) {
        }

        // 键盘释放函数
        public void keyReleased(KeyEvent e) {
        }

        // 实现焦点监听器接口
        // 实现获得焦点函数
        public void focusGained(FocusEvent e) {
            JTextField text = (JTextField) e.getSource();
            text.setText(null); // 每一个组件获得焦点后，将内容设置为空
        }

        // 实现失去焦点函数
        public void focusLost(FocusEvent e) {
        } // 这个 Lost 没有 ed
    }
}
