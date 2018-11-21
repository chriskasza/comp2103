#!/bin/bash
#####################################################################
#  Author:     Chris Kasza
#  Student #:  100133723
#  Course:     COMP 2103 N1
#  Version:    1.0
#  File:       phonebook.sh
# 
#  Telephone book program that has the following functionality:
#  1. search book
#  2. add entry
#  3. remove entry
#  4. list all entries
#####################################################################

prompt=


#  print the main menu and return user's menu choice
mainMenu() {
	printf "\nAvailable commands:\n"
	printf "\t1. Look someone up\n"
	printf "\t2. Add someone to the phone book\n"
	printf "\t3. Remove someone from the phone book\n"
	printf "\t4. List all names and numbers in the phone book\n"
	printf "\t5. Change the prompt\n"
	printf "\t6. See the menu\n"
	printf "\t7. Exit the program\n"
	printf "Please select one of the above (1-6): "
}

# find entry based on string
search() {
	printf "\nEnter name to look up: "
	read term

	numFound=`grep "$term" $1 | wc -l`
	
	echo "There are $numFound items: \n"

	count=1
	grep "$term" $1 | while read line
	do
		echo "#$count:"
		echo $line | tr '?' "\n"
		count=`expr $count + 1`
	done

	return $count
}

# add an entry to the phone book
addEntry() {
	printf "\nType in your entry, terminate with a single RETURN on the line: \n>> "
	read name
	if [ "$name" = "" ]
	then
		echo "no entry provided"
		return 0
	else
		printf "%s?" "$name" >> $1
	fi
	
	printf ">> "
	while read line
	do
		if [ "$line" = "" ]
		then
			printf "\n" >> $1
			printf "%s added to the book\n" "$name"
			break
		else
			printf "%s?" "$line" >> $1
			printf ">> "
		fi
	done
}

# remove an entry from the phone book
delEntry() {
	printf "\nEnter name to remove: "
	read term

	numFound=`grep "$term" $1 | wc -l`
	
	echo "There are $numFound items: \n"

	count=1
	grep "$term" $1 | while read line
	do
		echo "#$count:"
		echo $line | tr '?' "\n"
		count=`expr $count + 1`
	done

	printf "Do you want to remove all found? y/[n] "
	read yn
	if expr "$yn" : '[Yy]' > /dev/null
	then
		grep -v "$term" $1 > temp.pbk
		mv temp.pbk $1
	fi
}

# print all entries in phone book
listAll() {
	numFound=`cat $1 | wc -l`
	
	echo "There are $numFound items: \n"

	count=1
	while read -r line
	do 
		echo "#$count:"
		echo $line | tr '?' "\n"
		count=`expr $count + 1`
	done < $1
}

# change the prompt (default: ':')
changePrompt() {
	read -r -p "Type in your new prompt: " prompt
}

# print prompt
printPrompt() {
	printf "\n%s: " "$prompt"
}

# return number of entries in phone book 
getNum() {
	a=0 
	
	while read line
	do
		if expr "$line" : '^--.*--$' > /dev/null
		then
			a=`expr $a + 1`
		fi
	done < $1 

	return $a
}


main() {
	printf "My Phone Book\n\n"
	printf "Enter the name of your phonebook file.  File should be in "
	printf "current directory.\n\$ "
	read file
	if ! test -e "$file"
	then
		printf "\n%s doesn't exist.  Do you want to create one? y/[n] " $file
		read yn
		if expr "$yn" : '[Yy]' > /dev/null
		then
			touch ./$file
			printf "$file created\n"
		else
			printf "\nGood bye...\n\n"
			exit
		fi
	fi

	menu=0
	mainMenu

	while true
	do
		read menu
		
		case "$menu" in
			1)
				search $file
				printPrompt
				;;
			2)
				addEntry $file
				printPrompt
				;;
			3)
				delEntry $file
				printPrompt
				;;
			4)
				listAll $file
				printPrompt
				;;
			5)
				changePrompt
				printPrompt
				;;
			6)
				mainMenu
				;;
			7)
				printf "\nGood bye...\n\n"
				exit
				;;
			*)
				printf "\n'%s' is not a recognized menu option\n" $menu
				printPrompt
				;;
		esac
	done
}  # main() 

main $*
