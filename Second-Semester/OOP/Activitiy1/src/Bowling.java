import java.util.Scanner;

public class Bowling {

	public static void main(String[] args) {
			
		Scanner input = new Scanner(System.in);
		int[][]frameArray = new int[10][2];
		int frameScore = 0;
		int totalScore = 0;
		boolean isStrike = false;
		boolean isSpare = false;
		
		for(int frame = 0; frame < 10 ; frame++)
		{
			for(int tries = 0 ; tries < 2 ; tries++)
			{
				
				
				System.out.println("Score: " + totalScore);
				System.out.println("Frame "+ (frame+1) + '\n');
				System.out.println("Roll: " + (tries+1) );
				frameArray[frame][tries] = input.nextInt();
				
				
				if(isSpare)
				{
					totalScore += frameArray[frame][tries]+10;
					isSpare = false;
				}
				
				
				
				
				if(tries == 1)	
					while(frameArray[frame][tries] > 10 - frameArray[frame][tries-1])
					{
						System.out.println("Invalid input. There are only "+(10-frameArray[frame][tries-1]) + " pins left.");
						frameArray[frame][tries] = input.nextInt();
					}
				
				
				
				frameScore += frameArray[frame][tries];
				
				
				if(frameArray[frame][tries] == 10)
				{
					System.out.println("STRIKE!");
					totalScore+= frameArray[frame][tries];
					isStrike = true;
					isSpare = false;
					break;
				}
				if(frameScore == 10)
				{
					isStrike = false;
					isSpare = true;
					System.out.println("SPARE!");
				}
				
				
			}
			if(frame != 0)	
			{
				totalScore += frameScore;
				frameScore = 0;
			}
		
			
		}

	}

}
