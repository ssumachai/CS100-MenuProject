#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

class Visitor{
	private:
		int veggie_count;
		int sauce_count;
		int extra_count;
		
		int toppings_count;
		int protein_count;
		
		std::string message;
	public:
		Visitor(){
			veggie_count = sauce_count = extra_count = toppings_count = protein_count = 0;
			message = "";
		}
		void visit_veggie(){++veggie_count;}
		int get_veggie(){return veggie_count;}
		
		void visit_sauce(){++sauce_count;}
		int get_sauce(){return sauce_count;}
		
		void visit_extra(){++extra_count;}
		int get_extra(){return extra_count;}

		void visit_burger(){
			int sum = veggie_count + sauce_count + extra_count;
			
			if(sum == 10){
				message = "You added everything you could! Maybe try some Wings or a Salad Next Time!";
			}
			else if(6 < sum && sum < 10){
				message = "You added some toppings, why not take that extra step and add more!";
			}
			else if(3 < sum && sum < 6){
				message = "Try something new! We have a lot to offer!";
			}
			else if(1 <= sum && sum < 3){
				message = "A bit picky are we?  That's fine, our burgers are still great!";
			}
			else{
				message = "Maybe try adding some toppings next time!  :(";
			}
		}
		
		void visit_wing_count(int num){
			switch(num){
				case 3:
					message = "Only 3? Let's shoot for 6!\n";
					break;
				case 6:
					message = "6 is half of 12!\n";
					break;
				case 9:
					message = "It's wing o'clock! Next, 12!\n";
					break;
				case 12:
					message = "12 reasons to be happy today!\n";
					break;
				default:
					break;
			}
		}
		
		void visit_wing_sauce(int num){
			switch(num){
				case 0:
					message = message + "Buffalo, BBQ, and Plain?  Let's coat all of them next time!\n";
					break;
				case 1:
					message = message + "Yessirrr! Fully coated wings!\n";
					break;
				case 2:
					message = message + "Buffalo and Plain? Let's get some BBQ in there!\n";
					break;
				case 3:
					message = message + "Buffalo Soldier! Why not try some Bold BBQ!\n";
					break;
				case 4: 
					message = message + "BBQ and Plain! Why not BBQ Blackout? :)\n";
					break;
				case 5:
					message = message +  "BBQ Supremacy! Not a fun of the Buff?\n";
					break;
				case 6:
					message = message + "Get some sauce in here! We have plenty!\n";
					break;
				default:
					break;
			}
		}
		
		void visit_fry(char c){
			switch(c){
				case 'R':
					message = message + "Next time try our curly fries!\n";
					break;
				case 'C':
					message = message + "Next time try our regular fries!\n";
					break;
				case 'H':
					message = message + "Prefer one or the other?  We love both!\n";
					break;
				case 'N':
					message = message + "Having trouble deciding? Next time get the halfsies!\n";
					break;
				default:
					break;
			}
		}

		void visit_dip(bool b){
			if(b){
				message = message + "Don't get lost in the (dipping) sauce\n";
			}
			else{
				message = message + "Your wings look lonely...Dip or Drown!\n";
			}
		}

		void visit_wing(){
				message = message + "We love Wing Lovers, but have you met our Burgers and Salads?\n";
		}
		
		
		void visit_lettuce(char c){
			switch(c){
				case 'R':
					message = message + "Romaine wasn't built in a day!\n";
					break;
				case 'I':
					message = message + "Titanic!  Wait, no Iceberg!\n";
					break;
				case 'S':
					message = message + "Caution: Spring Mix does not bring forth Spring\n";
					break;
				case 'K':
					message = message + "Oh Kale Yeah!\n";
					break;
				default:
					break;
			}
		}
	
		void visit_toppings(){++toppings_count;}
		int get_toppings(){return toppings_count;}

		void visit_proteins(){++protein_count;}
		int get_protein(){return protein_count;}

		void visit_dressing(char c){
			switch(c){
				case 'C':
					message = message + "Don't stab the salad, Caesar\n";
					break;
				case 'R':
					message = message + "Ranch made in kitchen (ironically)\n";
					break;
				case 'B':
					message = message + "Why so Blue Cheese?\n";
					break;
				case 'V':
					message = message + "We go together like Vinegar and Oil...?\n";
					break;
				case 'S':
					message = message + "South West...wait where are we?\n";
					break;
				case 'N':
					message = message + "Eek! A Salad with no Dress(ing)!\n";
					break;
				default:
					break;
			}
		}
		void visit_salad(){
			int sum = toppings_count + protein_count;
			
			if(sum == 12){
				message = message + "You put everything on! Wow, have you considered doing the same with a Burger?\n";
			}
			if(sum >= 6 && sum <= 11){
				message = message + "Why not add just a little bit more!\n";
			}
			if(sum >= 1 && sum < 6){
				message = message + "Your salad looks a bit lonely, why not give it some friends?\n";
			}
			else{
				message = message + "Why. Why is your salad like this\n";
			}
		}

		void visit_student(){
			message = message + "Good Luck with Finals!\n";
		}
		void visit_employee(){
			message = message + "Your break started now.  Just kidding, enjoy!\n";
		}
		void visit_senior(){
			message = message + "Thank you for all the hard work! UCR loves you!\n";
		}
		void visit_veteran(){
			message = message + "This is the least we can do.  Thank you\n";
		}
		std::string get_message(){return message;}

};

#endif // __VISITOR_HPP__
	
