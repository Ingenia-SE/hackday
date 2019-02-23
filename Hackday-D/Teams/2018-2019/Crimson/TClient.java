import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;


public class TClient extends JFrame {
    BufferedImage bi;
    JButton btn;
    ServerSocket serverSocket;
    Socket socket;
    public TClient() {
        super("TClient");
        bi = createImage();
        this.add(btn = new JButton("Send"), BorderLayout.NORTH);
        this.add(new JLabel(new ImageIcon(bi)), BorderLayout.CENTER);
        this.setSize(200, 180);
        this.setVisible(true);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        try{
           serverSocket = new ServerSocket(8000);
           socket = serverSocket.accept();
       }
       catch(IOException ex){
        System.err.println(ex);
    }
    btn.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent arg0) {
            try {
                ImageIO.write(bi, "PNG", socket.getOutputStream());
                System.out.println("Enviado");
            } catch (IOException e) {
                    // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    });
}
public BufferedImage createImage() {
    BufferedImage bi = new BufferedImage(100, 100,
        BufferedImage.TYPE_INT_RGB);
    Graphics2D g2 = (Graphics2D) bi.getGraphics();
    g2.setPaint(Color.YELLOW);
    g2.fillRect(0, 0, 100, 100);
    g2.setPaint(Color.red);
    g2.fillRect(10, 10, 60, 60);
    g2.setPaint(Color.CYAN);
    g2.fillOval(30, 30, 60, 60);
    return bi;
}
public static void main(String[] args) {        
    new TClient();
}
}