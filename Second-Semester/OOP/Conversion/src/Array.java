import java.util.Scanner;

public class Array {

	public static void main(String[] args) {
			Scanner op = new Scanner(System.in);
			int Num; 
			int array[];
			System.out.println("Enter number of items");
			Num = op.nextInt();
			
			array = new int[Num];
			
			System.out.println("Input items");
			for(int a = 0; a < Num; a++)
			{
				
				array[a] = op.nextInt();
			}
			
			for(int item = 0; item < Num; item++)
			{
				System.out.println(item + ":");
				for(int ar = 0 ; ar < array[item]; ar++)
				{
					System.out.print("*");
				}
			}

	}

}
