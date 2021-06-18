import javax.swing.*;

public class JMenuDemo extends JFrame {
    private JPanel p;
    private JMenuBar menuBar;
    private JMenu menuFile, menuEdit, menuHelp, menuNew;
    private JMenuItem miSave, miExit, miCopy, miPost, miAbout, miC, miJava, miEmpty;

    public JMenuDemo() {
        super("菜单");
        p = new JPanel();
        menuBar = new JMenuBar();
        this.setJMenuBar(menuBar);
        menuFile = new JMenu("文件");
        menuEdit = new JMenu("编辑");
        menuHelp = new JMenu("帮助");
        menuNew = new JMenu("新建");
        menuBar.add(menuFile);
        menuBar.add(menuEdit);
        menuBar.add(menuHelp);
        menuFile.add(menuNew);
        menuFile.addSeparator();
        miSave = new JMenuItem("保存");
        miExit = new JMenuItem("退出");
        miCopy = new JMenuItem("复制");
        miPost = new JMenuItem("粘贴");
        miAbout = new JMenuItem("关于");
        miC = new JMenuItem("C++");
        miJava = new JMenuItem("JAVA");
        miEmpty = new JMenuItem("空白文档");
        menuFile.add(miSave);
        menuFile.add(miExit);
        menuEdit.add(miCopy);
        menuEdit.add(miPost);
        menuHelp.add(miAbout);
        menuNew.add(miC);
        menuNew.add(miJava);
        menuNew.add(miEmpty);
        add(p);
        setSize(300, 250);
        setLocation(100, 100);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        JMenuDemo f = new JMenuDemo();
        f.setVisible(true);
    }
}
