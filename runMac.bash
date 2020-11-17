
echo "Getting everything ready"
make hangman
echo "##################################             This should be one line             ##################################"
echo "Ready to start?"

function pause(){
 read -s -n 1 -p "Press any key to continue . . ."
 echo ""
 clear
}
 
## Pause it ##
pause
 
## rest of script below
./hangman
