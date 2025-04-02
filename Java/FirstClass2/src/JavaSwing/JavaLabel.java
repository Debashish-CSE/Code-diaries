package JavaSwing;

import java.awt.Color;
import java.awt.Font;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class JavaLabel {
	
	public static void main(String[] args) {
		
		//JLabel = a GUI display area for a string, an image or both
		
		ImageIcon image = new ImageIcon("D:/Programming/smile.png");
		
		JLabel label = new JLabel();  //create a label
		label.setText("Hi, how are you?"); //set text of label
		label.setIcon(image); //set image as label
		label.setHorizontalTextPosition(JLabel.CENTER); //set text LEFT,CENTER,RIGHT OF ImageIcon
		label.setVerticalTextPosition(JLabel.TOP);  //set text TOP,CENTRE,BOTTOM of ImageIcon
		label.setForeground(new Color(0x000000));
		label.setFont(new Font("MV Boli",Font.PLAIN,20));
		
		JFrame frame = new JFrame();  
		frame.setTitle("How to show labels");   
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
		frame.setResizable(false);   
		frame.setSize(600,600);  
		frame.setVisible(true);
		frame.add(label); //add label to frame
		
	}
}
