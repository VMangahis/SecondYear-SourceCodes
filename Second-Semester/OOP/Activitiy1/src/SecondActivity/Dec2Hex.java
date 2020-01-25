package SecondActivity;

import java.util.Scanner;

public class Dec2Hex {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		int decimal = 0;
		double tempDec = 0.0;
		int quotient = 0;
		int wholeNumber = 0;
		String output = " ";
		String finalOutput = "";
		System.out.println("Input decimal to be converted to hexadecimal");
		decimal = in.nextInt();
		while(decimal != 0)
		{
			
			tempDec = decimal/16.0;
			tempDec = tempDec - (int)tempDec;
			decimal/=16;
			quotient = (int) (tempDec*16);
			
			
			switch(quotient)
			{
				case 10:
					output+="a";
					break;
				
				case 11:
					output+="b";
					break;
					
				case 12:
					output+="c";
					break;
					
				case 13:
					output+="d";
					break;
					
				case 14:
					output+="e";
					break;
					
				case 15:
					output+="f";
					break;
					
				default:
					output+=Integer.toString(quotient);
					break;
			}
		}	
		for(int rev = output.length()-1; rev>=0; rev--)
		{
			finalOutput+=output.charAt(rev);
		}
		
		System.out.println("Hex: " + finalOutput);
		
		
		

	}

}
