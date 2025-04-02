package JavaSwing;

import java.lang.Math;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.*;

public class WeekDayCalculator {
	
	public int leapYear(int year) {
		if(year%400==0){
			return 1;
		}
		else if((year%100!=0)&&(year%4==0)){
			return 1;
		}
		else{
			return 0;
		}
	}

	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.setTitle("Weekday Calculator");
		frame.setSize(600,300);
		frame.setResizable(false);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new FlowLayout());
		
		JLabel label1 = new JLabel("Please input day, month, year as integers");
		/*JLabel label2 = new JLabel();
		JLabel label3 = new JLabel();*/
		JButton button = new JButton("Find weekday");
		JTextField day = new JTextField();
		JTextField month = new JTextField();
		JTextField year = new JTextField();
		JTextField weekday = new JTextField();
		
		day.setPreferredSize(new Dimension(100, 30));
		month.setPreferredSize(new Dimension(100, 30));
		year.setPreferredSize(new Dimension(100, 30));
		weekday.setPreferredSize(new Dimension(100, 30));
		weekday.setEditable(false);
		
		frame.add(label1);
		frame.add(day);
		frame.add(month);
		frame.add(year);
		frame.add(button);
		frame.add(weekday);
		
		WeekDayCalculator calc = new WeekDayCalculator();
		
		button.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				int d = Integer.parseInt(day.getText());
				int m = Integer.parseInt(month.getText());
				int y = Integer.parseInt(year.getText());
				int t=0, td;
				int isLeapYear = calc.leapYear(y);
				
				int days[] = {0,0,31,28,31,30,31,30,31,31,30,31,30}; 
				for(int i=1; i<=m; i++) {
					t += days[i];
				}
				t += d;
				
				if(isLeapYear == 0) td = t;
				else td = t+1;
				
				int k = (y-1) + (int)Math.floor((y-1)/4) + td;				
				if(k%7 == 0) weekday.setText("Saturday");
				if(k%7 == 1) weekday.setText("Sunday");
				if(k%7 == 2) weekday.setText("Monday");
				if(k%7 == 3) weekday.setText("Tuesday");
				if(k%7 == 4) weekday.setText("Wednesday");
				if(k%7 == 5) weekday.setText("Thursday");
				if(k%7 == 6) weekday.setText("Friday");
				
			}
		});
		
		//Make frame visible
		frame.setVisible(true);
	}

}
