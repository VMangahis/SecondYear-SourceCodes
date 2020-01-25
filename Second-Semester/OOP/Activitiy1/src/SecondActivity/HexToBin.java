package SecondActivity;

import java.util.Scanner;

public class HexToBin {

	public static void main(String[] args) {
		String hex;
		String output = " ";
		String hexBits[] = {"0000", "0001", "0010", "0011","0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100","1101","1110","1111"};
		Scanner in = new Scanner(System.in);
		System.out.println("Enter hexadecimal value");
		hex = in.nextLine();
		for(int conv = 0; conv < hex.length(); conv++)
		{
			
			switch(hex.charAt(conv))
			{
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					output+=(hexBits[Integer.parseInt(Character.toString(hex.charAt(conv)))] + " ");
					break;
					
				case 'a':
					output+=(hexBits[10] + " ");
					break;
				case 'b':
					output+=(hexBits[11] + " ");
					break;
				case 'c':
					output+=(hexBits[12]+ " ");
					break;
				case 'd':
					output+=(hexBits[13]+ " ");
					break;
					
				case 'e':
					output+=(hexBits[14] + " ");
					break;
					
				case 'f':
					output+=(hexBits[15] + " ");
					break;
						
			}
		}
		
		System.out.println("Output: " + output);

	}

}
