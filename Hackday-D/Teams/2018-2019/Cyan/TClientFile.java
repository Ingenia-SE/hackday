/*
 * Copyright (c) 2019, INGENIA SE. All rights reserved.
 *
 * Sample client to send target image to the server.
 *
 * https://docs.oracle.com/javase/8/docs/api/javax/imageio/ImageIO.html
 */

import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.net.Socket;
import javax.imageio.ImageIO;

// This simple client reads an image from the file "target.png" and 
// sends it to a local image server hearing at port 7777

public class TClientFile
{
    public static void main(String [] args)
    {
        String serverName = "127.0.0.1";
        int port = 7777;
        String filename = "/home/alumno/Escritorio/imagen2.jpg";

        try
        {
            Socket client = new Socket(serverName, port);       // Open socket
            File imagefile = new File(filename);                // Open file
            BufferedImage bimg = ImageIO.read(imagefile);       // Read image
            ImageIO.write(bimg,"JPG",client.getOutputStream()); // Send image
            client.close();
        } catch(IOException e) {
            e.printStackTrace();
        }
    }
}