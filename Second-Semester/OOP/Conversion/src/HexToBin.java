import java.util.Scanner;

public class HexToBin {

	public static void main(String[] args) {
		Scanner op = new Scanner(System.in);
		String input = " ";
		String output = " ";
		String[] hexBits = {"0000", "0001", "0010", "0011", 
							"0100", "0101", "0110", "0111",
							"1000", "1001", "1010", "1011",
							"1100", "1101", "1110", "1111"};
		
		input = op.nextLine();
		
		for(int a = 0 ; a < input.length(); a++)
		{
			switch(input.charAt(a))
			{
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case "7":
					
					break;
			}
		}
		
		

	}

}
