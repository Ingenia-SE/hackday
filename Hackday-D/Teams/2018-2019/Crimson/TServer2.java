import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.net.Socket;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;


public class TServer2 extends JFrame {
    public TServer2() {
        super("TServer2");
        this.setSize(200, 180);
        this.setVisible(true);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        try {
            Socket socket = new Socket("127.0.0.1", 8000);
            BufferedImage image = ImageIO.read(socket.getInputStream());
            this.add(new JLabel(new ImageIcon(image)), BorderLayout.CENTER);
        } catch (IOException e) {
            // TODO Auto-generated catch block
            System.err.println(e);
        }
    }
    public static void main(String[] args) {        
        new TServer2();
    }
}