import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class JComboBoxDemo {
    public static void main(String arugs[]) {
        new Jfs();
    }
}

class Jfs extends JFrame implements ItemListener {
    JTextPane txt = new JTextPane();

    Jfs() {
        setSize(200, 200);
        setVisible(true);
        setLayout(new FlowLayout());
        JComboBox box = new JComboBox();
        box.addItem("上海");
        box.addItem("北京");
        box.addItem("广州");
        box.addItem("深圳");
        add(box);
        txt.setText("你选择了");
        add(txt);
        box.addItemListener(this);
        validate();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void itemStateChanged(ItemEvent e) {
        // TODO Auto-generated method stub
        String s = (String) e.getItem().toString();
        txt.setText("你选择了" + s);
    }

}
