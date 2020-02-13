import java.util.Scanner;

public class Dec2Hex {

	public static void main(String[] args) {
		double decimal = 0.0;
		int temp = 0;
		int dec = 0;
		
		double quotient = 1.0;
		String output = "";
		String fin = "";
		Scanner in = new Scanner(System.in);
		System.out.println("Input decimal");
		dec = in.nextInt();
		
		while(quotient != 0)
		{
			quotient = dec/16.0;
			if(quotient == 0)
			{
				break;
			}
			dec/=16.0;
			dec = (int)dec;
			decimal = quotient - (int)quotient;
			decimal*=16;
			temp = (int)decimal;
			
			switch(temp)
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
					output+=Integer.toString(temp);
					break;
			}
		}
		
		for(int rev = output.length()-1; rev>=0; rev--)
		{
			fin+=output.charAt(rev);
		}
		System.out.println(fin);
		
		

	}

}
