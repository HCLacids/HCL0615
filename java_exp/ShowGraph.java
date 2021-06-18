import java.io.File;

import javax.swing.*;

public class ShowGraph extends JFrame {
    private JLabel label = new JLabel();
    private JPanel p;
    private JMenuBar menuBar;
    private JMenu menuFile;
    private JMenuItem miSave, miExit;
    private JFileChooser chooser;

    public ShowGraph() {
        super("菜单");
        p = new JPanel();
        menuBar = new JMenuBar();
        this.setJMenuBar(menuBar);
        menuFile = new JMenu("file");
        menuBar.add(menuFile);
        menuFile.addSeparator();
        miSave = new JMenuItem("open");
        miExit = new JMenuItem("close");
        menuFile.add(miSave);
        menuFile.add(miExit);
        add(p);
        add(label);
        chooser = new JFileChooser();
        chooser.setCurrentDirectory(new File("."));
        setSize(300, 250);
        setLocation(100, 100);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 将子菜单加入菜单条
        miSave.addActionListener(event -> {
            int r = chooser.showOpenDialog(null);
            if (r == JFileChooser.APPROVE_OPTION) {
                String name = chooser.getSelectedFile().getPath(); // 返回选中的文件名
                label.setIcon(new ImageIcon(name)); // 将返回选中的文件名显示在窗体中
            }
        });
    }

    public static void main(String[] args) {
        ShowGraph f = new ShowGraph();
        f.setVisible(true);
    }
}
