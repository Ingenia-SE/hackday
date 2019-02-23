/*
 * Copyright (c) 2016, INGENIA SE. All rights reserved.
 *
 * Server to receive target image from drone control app.
 *
 * https://docs.oracle.com/javase/8/docs/api/javax/imageio/ImageIO.html
 */

import java.awt.image.BufferedImage;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

// The TServer is the target server for the Hackday-D exercise. It receives
// images of the targets and displays them.

public class TServer extends Thread{
  private ServerSocket serverSocket;
  Socket server;

  public TServer(int port) throws IOException, Exception
  {
    serverSocket = new ServerSocket(port);
    serverSocket.setSoTimeout(600000);
  }

  public void run()
  {
   System.out.println("Target server start !");

   while(true)
   { 
     try
     {
      System.out.println("Target server waiting for image ...");
      server = serverSocket.accept();           
      BufferedImage img=ImageIO.read(ImageIO.createImageInputStream(server.getInputStream()));
      System.out.println("Target server received image.");
      JFrame frame = new JFrame();
      frame.getContentPane().add(new JLabel(new ImageIcon(img)));
      frame.pack();
      System.out.println("Target server displaying image.");
      frame.setVisible(true);                  
    }
    catch(SocketTimeoutException st)
    {
     System.out.println("Target server socket timed out (600s)!");
     break;
   }
   catch(IOException e)
   {
    e.printStackTrace();
    break;
  }
  catch(Exception ex)
  {
    System.out.println(ex);
  }
}
}

public static void main(String [] args) throws IOException, Exception
{
              Thread t = new TServer(17777); // A new server hearing at port 1777
              t.start();
            }
          }