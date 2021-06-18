import java.awt.Graphics;
import java.awt.Image;
import javax.swing.JApplet;

public class ImgPlayer extends JApplet {
    private Image img;

    public void init() {
        img = getImage(getCodeBase(), "car.jpg");
    }

    public void paint(Graphics g) {
        g.drawString("Hello World", 25, 50);
    }
}
