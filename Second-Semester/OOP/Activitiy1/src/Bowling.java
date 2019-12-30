import java.util.Scanner;

public class Bowling {

	public static void main(String[] args) {
		// Perfect = 300 Score
		Scanner input = new Scanner(System.in);
		int[][] rolls = new int[10][2];
		int frameScore = 0;
		int pins = 10;
		int totalScore = 0;
		boolean isStrike = false;
		boolean isSpare = false;
		
		
		for(int frame = 0 ; frame < 10 ; frame++)
		{
			System.out.println("Frame: " + (frame+1));
			pins = 10;
			for(int roll = 0; roll < 2; roll++)
			{
				System.out.println("Roll: " + (roll+1));
				System.out.println("Number of pins knocked down (" + (pins) + " left):" );
				System.out.println("Score: " + totalScore);
				rolls[frame][roll] = input.nextInt();
				while(rolls[frame][roll] > pins || rolls[frame][roll] < 0)
				{
					System.out.println("Input cannot be greater than the amount of pins left or a negative number. Please try again.");
					System.out.println("Number of pins knocked down (" + (pins) + " left):" );
					rolls[frame][roll] = input.nextInt();
				}
				
				if(roll == 0 && isSpare)
				{
					totalScore+= (rolls[frame][roll]+ 10); 	// 10 + next number of pins knock down 
					isSpare = false;
				}
				
				if(roll == 1 && isStrike)		// 10 + total pins knocked down in the next frame 
				{
					totalScore += (rolls[frame][roll]+ rolls[frame][roll-1] + 10);  
					isStrike = false;
				}
				
				
				
				pins-=rolls[frame][roll];
				
				if(pins == 0 && roll == 0) 		// Strike
				{
					System.out.println("STRIKE!");
					isStrike = true;
					break;
				}
				else if(pins == 0 && roll == 1) // Spare
				{
					System.out.println("SPARE!");
					isSpare = true;
				}
				else if(roll == 1) 				// Open Frame
				{
					System.out.println("OPEN FRAME!");
					totalScore+=(rolls[frame][roll] + rolls[frame][roll-1]);
				}
			}
		}
	}

}
