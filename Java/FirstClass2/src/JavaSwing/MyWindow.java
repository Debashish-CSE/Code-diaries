package JavaSwing;
import javax.swing.*;
import java.awt.event.*;
import java.awt.FlowLayout;
//import java.awt.BorderLayout;

public class MyWindow {

	public static void main(String[] args) {
		JFrame frame = new JFrame("My Window");
		frame.setTitle("Weird");
		frame.setSize(600,600);
		frame.setResizable(false);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		FlowLayout flow = new FlowLayout();
		//BorderLayout border = new BorderLayout();
		
		frame.setLayout(flow);
		
		JButton button1 = new JButton("Click Me");
		JButton button2 = new JButton("I love you");
		JLabel label1 = new JLabel("Nothing");
		JLabel label2 = new JLabel("Nothing");
		frame.add(button1);
		frame.add(button2);
		frame.add(label1);
		frame.add(label2);
		frame.setVisible(true);
		//frame.show();
		
	}

}
