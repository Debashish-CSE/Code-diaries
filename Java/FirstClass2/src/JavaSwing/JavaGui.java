package JavaSwing;

import java.awt.Color;
import javax.swing.ImageIcon;
import javax.swing.JFrame;

public class JavaGui {
	
	public static void main(String[] args) {
		
		//JFrame = a GUI window to add components to
		
		JFrame frame = new JFrame();  //creates a frame
		frame.setTitle("This is the title");   //sets title of frame
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //exit out of application
		//frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE); //nothing happens after clicking exit
		frame.setResizable(false);   //prevent frame from being resized
		frame.setSize(600,600);      //sets the x-dimension and y-dimension of frame
		frame.setVisible(true);      //make frame visible
		
		ImageIcon image = new ImageIcon("D:/Programming/smile.png"); //create an ImageIcon
		frame.setIconImage(image.getImage()); //change icon of frame
		
		//frame.getContentPane().setBackground(Color.yellow);  //change color of background
		frame.getContentPane().setBackground(new Color(255,255,100)); //Color(red,green,blue), make new colors changing the numbers
		//frame.getContentPane().setBackground(new Color(0xFFFF00));  //Color(0x......) hexadecimal value for colors
		
		
	
	}

}
