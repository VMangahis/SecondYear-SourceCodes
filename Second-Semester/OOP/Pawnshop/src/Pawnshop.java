
class Cebuana extends Pawnshop{
	
	final int rate = 10;
	
	Cebuana(double princAmount, int installment ) {
		super(princAmount, installment);
		this.rateofInterest = (((double)rate/12)*100)/100.0;
		
	}
	double computeEMI()
	{
		System.out.println("Cebuana Pawnshop");	
		System.out.println("Principal Amount : P " + principalAmount);
		System.out.println("Number of installments: "+ installment);
		System.out.println("Rate of Interest: " + "10%");
		this.emi = (principalAmount*rateofInterest*Math.pow((1+rateofInterest), installment)) / Math.pow((1+rateofInterest), installment-1);
		return this.emi;
	}
	
}


class Palawan extends Pawnshop{
	
	final int rate = 11;
	
	Palawan(double princAmount, int installment)
	{
		super(princAmount, installment);
		this.rateofInterest = (((double)rate/12)*100)/100;
		
	}
	
	double computeEMI()
	{
		System.out.println("Palawan Pawnshop");
		System.out.println("Principal Amount : P " + principalAmount);
		System.out.println("Number of installments: "+ installment);
		System.out.println("Rate of Interest: " + "11%");
		
		this.emi = (principalAmount*rateofInterest*Math.pow((1+rateofInterest), installment)) / Math.pow((1+rateofInterest), installment-1);
		return this.emi;
	}
	
}



class Luwilyer extends Pawnshop{
	
	final int rate = 12;
	Luwilyer(double princAmount, int installment)
	{
		super(princAmount, installment);
		this.rateofInterest = (((double)rate/12)*100)/100;
	}
	
	double computeEMI()
	{
		System.out.println("Luwilyer Pawnshop");
		System.out.println("Principal Amount : P " + principalAmount);
		System.out.println("Number of installments: "+ installment);
		System.out.println("Rate of Interest: " + "12%");
		

		this.emi = (principalAmount*rateofInterest*Math.pow((1+rateofInterest), installment)) / Math.pow((1+rateofInterest), installment-1);
		return this.emi;
	}
	
}



public class Pawnshop {
	
	 double principalAmount = 2000.0;
	double emi=0.0;
	
	int installment = 2;
	int inteRate=0;
	double rateofInterest = (((double)inteRate/12)*100)/100.0;
	
	Pawnshop(double princAmount, int installment)
	{
		principalAmount = princAmount;
		this.installment = installment;
	}
	
	
	double computeEMI()
	{
		
		emi = (principalAmount*rateofInterest*Math.pow((1+rateofInterest), installment)) / Math.pow((1+rateofInterest), installment-1);
		return emi;
	}

	
	public static void main(String [] args)
	{
		Cebuana cebObj = new Cebuana(1000,2);
		System.out.println("EMI: "+cebObj.computeEMI());
		System.out.println();
		Palawan palObj = new Palawan(1000,2);
		System.out.println();
		System.out.println("EMI: "+palObj.computeEMI());
		Luwilyer luwObj = new Luwilyer(1000,2);
		System.out.println();
		System.out.println("EMI: "+luwObj.computeEMI());
		System.exit(0);
	}
	

}

