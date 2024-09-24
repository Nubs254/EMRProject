#define MAX_FNAME_LEN 32
#define MAX_LNAME_LEN 32
#define MAX_STREET_LEN 64
#define MAX_CITY_LEN 64
#define MAX_STATE_LEN 3
#define MAX_ICD_LEN 10
#define MAX_ICD_NUM 4
#define IN_BUFFER 1024

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

enum stAbb{
    AL, AK, AZ, AR, CA, CO, CT, DE, DC, FL, GA, HI, ID, IL, IN, IA, KS,
    KY, LA, ME, MD, MA, MI, MN, MS, MO, MT, NE, NV, NH, NJ, NM, NY, NC,
    ND, OH, OK, OR, PA, RI, SC, SD, TN, TX, UT, VT, VA, WA, WV, WI, WY,
    NONE
};
enum phoneType{
    WORK, CELL, HOME
};
struct PHONE_INFO{
    unsigned short areaCode;
    unsigned int phoneNum;
    enum phoneType pType;
};
struct ICD_INFO{
    char* codes;
    unsigned int dates;
    size_t len;
};
struct userInfo{
    char* fName;
    char* lName;
    unsigned short addNum;
    char* street;
    char* city;
    enum stAbb stateEnum;
    unsigned int zip;
    unsigned short plusFour;
    struct PHONE_INFO phone;
    struct ICD_INFO* ICD;
    unsigned int recNum;
}USER;
struct PERAMS{
    bool reload;
    char* fileName;
    bool codeCntChange;
    unsigned int codeCnt;
}usrPerams;
bool isValidState(char stateChar1, char stateChar2){
    switch(stateChar1){
        case 'A':
        switch(stateChar2){
            case 'K':
                USER.stateEnum = AK;
                break;
            case 'L':
                USER.stateEnum = AL;
                break;
            case 'R':
                USER.stateEnum = AR;
                break;
            case 'Z':
                USER.stateEnum = AZ;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'C':
        switch(stateChar2){
            case 'A':
                USER.stateEnum = CA;
                break;
            case 'O':
                USER.stateEnum = CO;
                break;
            case 'T':
                USER.stateEnum = CT;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'D':
        switch(stateChar2){
            case 'E':
                USER.stateEnum = DE;
                break;
            case 'C':
                USER.stateEnum = DC;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'F':
        switch(stateChar2){
            case 'L':
                USER.stateEnum = FL;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'G':
        switch(stateChar2){
            case 'A':
                USER.stateEnum = GA;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'H':
        switch(stateChar2){
            case 'I':
                USER.stateEnum = HI;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'I':
        switch(stateChar2){
            case 'D':
                USER.stateEnum = ID;
                break;
            case 'L':
                USER.stateEnum = IL;
                break;
            case 'N':
                USER.stateEnum = IN;
                break;
            case 'A':
                USER.stateEnum = IA;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'K':
        switch(stateChar2){
            case 'S':
                USER.stateEnum = KS;
                break;
            case 'Y':
                USER.stateEnum = KY;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'L':
        switch(stateChar2){
            case 'A':
                USER.stateEnum = LA;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'M':
        switch(stateChar2){
            case 'E':
                USER.stateEnum = ME;
                break;
            case 'D':
                USER.stateEnum = MD;
                break;
            case 'A':
                USER.stateEnum = MA;
                break;
            case 'I':
                USER.stateEnum = MI;
                break;
            case 'N':
                USER.stateEnum = MS;
                break;
            case 'O':
                USER.stateEnum = MO;
                break;
            case 'T':
                USER.stateEnum = MT;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'N':
        switch(stateChar2){
            case 'E':
                USER.stateEnum = NE;
                break;
            case 'V':
                USER.stateEnum = NV;
                break;
            case 'H':
                USER.stateEnum = NH;
                break;
            case 'J':
                USER.stateEnum = NJ;
                break;
            case 'M':
                USER.stateEnum = NM;
                break;
            case 'Y':
                USER.stateEnum = NY;
                break;
            case 'C':
                USER.stateEnum = NC;
                break;
            case 'D':
                USER.stateEnum = ND;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'O':
        switch(stateChar2){
            case 'H':
                USER.stateEnum = OH;
                break;
            case 'K':
                USER.stateEnum = OK;
                break;
            case 'R':
                USER.stateEnum = OR;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'P':
        switch(stateChar2){
            case 'A':
                USER.stateEnum = PA;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'R':
        switch(stateChar2){
            case 'I':
                USER.stateEnum = RI;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'S':
        switch(stateChar2){
            case 'C':
                USER.stateEnum = SC;
                break;
            case 'D':
                USER.stateEnum = SD;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'T':
        switch(stateChar2){
            case 'N':
                USER.stateEnum = TN;
                break;
            case 'X':
                USER.stateEnum = TX;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'U':
        switch(stateChar2){
            case 'T':
                USER.stateEnum = UT;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'V':
        switch(stateChar2){
            case 'T':
                USER.stateEnum = VT;
                break;
            case 'A':
                USER.stateEnum = VA;
                break;
            default:
                USER.stateEnum = NONE;
        }
        break;

        case 'W':
        switch(stateChar2){
            case 'A':
                USER.stateEnum= WA;
                break;
            case 'V':
                USER.stateEnum = WV;
                break;
            case 'I':
                USER.stateEnum = WI;
                break;
            case 'Y':
                USER.stateEnum = WY;
                break;
            default:
                USER.stateEnum = NONE;
        }
        default:
            USER.stateEnum = NONE;
    }
    if(USER.stateEnum != NONE){
        return true;
    }
    else{
        return false;
    }
}
bool isValidDate(unsigned short month, unsigned short day, unsigned short year){
    if(month == 2){
        if(year % 400 == 0 && day > 0 && day < 30){
            return true;
        }
        else if(year % 100 == 0 && day > 0 && day < 29){
            return true;
        }
        else if(year % 4 == 0 && day > 0 && day < 30){
            return true;
        }
        else if(day > 0 && day < 29){
            return true;
        }
        else{
            return false;
        }
    }
    else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 0 && day < 31){
        return true;
    }
    else if(month > 0 && month < 13 && day > 0 && day < 32){
        return true;
    }
    else{
        return false;
    }
}
bool getValidStr(char* strBuff, char* input, size_t MAX_SIZE){
    bool errorFree = false;
    fgets(strBuff, IN_BUFFER, stdin);
        if(strBuff[0] == '\n' || strBuff[0] == '\0' || strlen(strBuff) == 0 || strBuff[0] == '\r'){
            errorFree = false;
            printf("\nNo %s was entered.", input);
        }
        else if(strlen(strBuff) > MAX_SIZE){
            errorFree = false;
            printf("\n%s has over %zu characters and is too long.", input, MAX_SIZE);
        }
        else if(strBuff[0] == ' '  || strBuff[0] == '\t'){
            errorFree = false;
            printf("\nUnnecessary whitespace entered at the beginning.");
        }
        else{
            errorFree = true;
        }
    return errorFree;
}
unsigned short getAdd(){
    unsigned short temp;
    printf("\nPlease provide the patient's home address number: ");
    scanf("%hu", &temp);
    getchar();
    return temp;
}
void getState(char* strBuff){
    bool errorFree = false;
    do{
        printf("\nPlease provide the two letter abbreviation (in CAPS) of the patient's home state: ");
        fgets(strBuff, IN_BUFFER, stdin);
        if(strBuff[0] == '\n' || strBuff[0] == '\0' || strlen(strBuff) == 0 || strBuff[0] == '\r'){
            errorFree = false;
            printf("\nNo state abbreviation was entered.");
        }
        else if(strlen(strBuff) > MAX_STATE_LEN){
            errorFree = false;
            printf("\nState abbreviation has over 2 characters and is too long.");
        }
        else if(strBuff[0] == ' '  || strBuff[0] == '\t'){
            errorFree = false;
            printf("\nUnnecessary whitespace entered at the beginning.");
        }
        else if(isValidState(strBuff[0], strBuff[1]) == false){
            errorFree = false;
            printf("\nAbbreviation entered is not a valid state abbreviation.");
        }
        else{
            errorFree = true;
        }
    }while(!errorFree);
}
unsigned int getZIPcode(){
    bool errorFree = false;
    unsigned int ZIP;
    do{
        printf("\nPlease provide the patient's ZIP code: ");
        scanf("%u", &ZIP);
        if(ZIP >= 1000 && ZIP <= 99950){
            errorFree = true;
        }
        else if(ZIP < 1000){
            errorFree = false;
            printf("\n%u is to small of a ZIP code, smallest valid ZIP is 1000.", ZIP);
        }
        else{
            errorFree = false;
            printf("\n%u is to large of a ZIP code, largest valid ZIP is 99950", ZIP);
        }
    }while(!errorFree);
    return ZIP;
}
unsigned short getZIPplusFour(){
    bool errorFree = false;
    unsigned short zipPlusFour;
    do{
        printf("\nPlease enter the extra four digits of the patient's ZIP code: ");
        scanf("%hu", &zipPlusFour);
        if(zipPlusFour <= 9999){
            errorFree = true;
        }
        else{
            printf("\n%u is to large of a +4 ZIP code, largest valid +4 ZIP is 9999", zipPlusFour);
        }
    }while(!errorFree);
    return zipPlusFour;
}
unsigned short getAreaCode(){
    bool errorFree = false;
    unsigned short temp;
    do{
        printf("\nPlease enter the patient's phone's area code: ");
        scanf("%hu", &temp);
        if(temp >= 200 && temp <= 999){
            errorFree = true;
        }
        else if(temp < 200){
            errorFree = false;
            printf("\nArea code entered is too small, smallest valid area code is 200");
        }
        else{
            errorFree = false;
            printf("\nArea code entered is too large, largest valid area code is 999");
        }
    }while(!errorFree);
    return temp;
}
unsigned int getPhoneNum(){
    bool errorFree = false;
    unsigned int pNum;
    do{
        printf("\nPlease enter the patient's phone number (NOT including area code): ");
        scanf("%u", &pNum);
        if(pNum >= 2010000 && pNum <= 9999999){
            errorFree = true;
        }
        else if(pNum < 2010000){
            errorFree = false;
            printf("\nPhone number entered is too small, smallest valid phone number is 2010000");
        }
        else{
            errorFree = false;
            printf("\nPhone number entered is too large, largest valid phone number is 9999999");
        }
    }while(!errorFree);
    getchar();
    return pNum;
}
void getPhoneType(char* strBuff){
    bool errorFree = false;
    do{
        printf("\nPlease enter the patient's phone type, \"W\" for Work, \"C\" for Cell, \"H\" for Home: ");
        fgets(strBuff, IN_BUFFER, stdin);
        if(strBuff[0] == '\n' || strBuff[0] == '\0' || strlen(strBuff) == 0 || strBuff[0] == '\r'){
            errorFree = false;
            printf("\nNo phone type was entered.");
        }
        else if(strBuff[0] == ' '  || strBuff[0] == '\t'){
            errorFree = false;
            printf("\nUnnecessary whitespace entered at the beginning.");
        }
        else if(strlen(strBuff) > 2){
            errorFree = false;
            printf("\nPhone type entered is more than a single character and is too long.");
        }
        else if(strBuff[0] == 'W' || strBuff[0] == 'w'){
            errorFree = true;
            USER.phone.pType = WORK;
        }
        else if(strBuff[0] == 'C' || strBuff[0] == 'c'){
            errorFree = true;
            USER.phone.pType = CELL;
        }
        else if(strBuff[0] == 'H' || strBuff[0] == 'h'){
            errorFree = true;
            USER.phone.pType = HOME;
        }
        else{
            errorFree = false;
            printf("\nPhone type entered is not a valid phone type.");
        }
    }while(!errorFree);
}
unsigned int getICDdate(int i){
    unsigned short tempDay;
    unsigned short tempMonth;
    unsigned short tempYear;
    unsigned int date;
    bool errorFree = false;
    do{
        printf("\nPlease enter the date when ICD code %u was last modified", i+1);
        printf("\nMonth(MM): ");
        scanf("%hu", &tempMonth);
        printf("\nDay(DD): ");
        scanf("%hu", &tempDay);
        printf("\nYear(YYYY): ");
        scanf("%hu", &tempYear);
        if(isValidDate(tempMonth, tempDay, tempYear)){
            errorFree = true;
            date = (tempMonth*1000000) + (tempDay*10000) + (tempYear);
        }
        else{
            errorFree = false;
            printf("%02hu/%02hu/%04hu is not a valid date, try again.", tempMonth, tempDay, tempYear);
        }
    }while(!errorFree);
    getchar();
    return date;
}
void spaceConv(char* str, char ret){
    unsigned int i;
    if(ret == 'P'){
        for(i = 0; i < strlen(str); i++){
            if(str[i] == ' '){
                str[i] = '+';
            }
        }
    }
    if(ret == 'S'){
        for(i = 0; i < strlen(str); i++){
            if(str[i] == '+'){
                str[i] = ' ';
            }
        }
    }
}
unsigned int getRecNum(){
    unsigned int recNum;
    bool errorFree = false;
    do{
        printf("\nPlease provide the patient's Record Number: ");
        scanf("%u", &recNum);
        if(recNum == 0){
            errorFree = false;
            printf("\n%u is not a vilid Record Number", recNum);
        }
        else{
            errorFree = true;
        }
    }while(!errorFree);
    return recNum;
}
void itoa(unsigned int num, char* strBuff, unsigned int mod, unsigned int numLen){
    size_t i = strlen(strBuff);
    unsigned int numCount = 0;
    while(num > 0){
        unsigned int digit = num/mod;
        num %= mod;
        mod /= 10;
        digit += 0x30;
        strBuff[i] = (char)digit;
        strBuff[i+1] = '\0';
        i++;
        numCount++;
    }
    for(numCount; numCount < numLen; numCount++){
        strBuff[i] = '0';
        strBuff[i+1] = '\0';
        i++;
    }
}
void getFileName(char* fn, char* ln, unsigned int recNum, char* strBuff){
    strcpy(strBuff, ln);
    strcat(strBuff, "_");
    strcat(strBuff, fn);
    strcat(strBuff, "_");
    itoa(recNum, strBuff, 1000000000, 10);
    strcat(strBuff, ".icd");
}
char getYorN(char* prompt){
    bool errorFree = false;
    char userChar;
    do{
        printf("\n%s, press \"Y\" for yes, or press \"N\" for no: ", prompt);
        scanf("%c", &userChar);
        if(userChar == 'Y' || userChar == 'y'){
            errorFree = true;
            userChar = 'Y';
        }
        else if(userChar == 'N'|| userChar == 'n'){
            errorFree = true;
            userChar = 'N';
        }
        else{
            printf("\n%c is not a valid input", userChar);
            errorFree = false;
        }
        getchar();
    }while(!errorFree);
    return userChar;
}
void saveAllInfo(FILE* saveFile){
    unsigned int i;
    fprintf(saveFile, "%u ", usrPerams.codeCnt);
    spaceConv(USER.fName, 'P');
    spaceConv(USER.lName, 'P');
    fprintf(saveFile, "%s %s ", USER.fName, USER.lName);
    fprintf(saveFile, "%hu ", USER.addNum);
    spaceConv(USER.street, 'P');
    spaceConv(USER.city, 'P');
    fprintf(saveFile, "%s %s ", USER.street, USER.city);
    fprintf(saveFile, "%d %u %hu ", USER.stateEnum, USER.zip, USER.plusFour);
    fprintf(saveFile, "%d %hu %u ", USER.phone.pType, USER.phone.areaCode, USER.phone.phoneNum);
    for(i = 0; i < usrPerams.codeCnt; i++){
        spaceConv(USER.ICD[i].codes, 'P');
        fprintf(saveFile, "%s %u ", USER.ICD[i].codes, USER.ICD[i].dates);
    }
}
void retAllInfo(FILE* saveFile, char* strBuff){
    unsigned int i;
    fscanf(saveFile, "%u", &(usrPerams.codeCnt));
    fscanf(saveFile, "%s", strBuff);
    USER.fName = (char*)malloc(strlen(strBuff) * sizeof(char));
    strcpy(USER.fName, strBuff);
    memset(strBuff, 0, IN_BUFFER);
    fscanf(saveFile, "%s", strBuff);
    USER.lName = (char*)malloc(strlen(strBuff) * sizeof(char));
    strcpy(USER.lName, strBuff);
    memset(strBuff, 0, IN_BUFFER);
    fscanf(saveFile, "%hu", &(USER.addNum));
    fscanf(saveFile, "%s", strBuff);
    USER.street = (char*)malloc(strlen(strBuff) * sizeof(char));
    strcpy(USER.street, strBuff);
    memset(strBuff, 0, IN_BUFFER);
    fscanf(saveFile, "%s", strBuff);
    USER.city = (char*)malloc(strlen(strBuff) * sizeof(char));
    strcpy(USER.city, strBuff);
    memset(strBuff, 0, IN_BUFFER);
    fscanf(saveFile, "%d", &(USER.stateEnum));
    fscanf(saveFile, "%u %hu", &(USER.zip), &(USER.plusFour));
    fscanf(saveFile, "%d", &(USER.phone.pType));
    fscanf(saveFile, "%hu", &(USER.phone.areaCode));
    fscanf(saveFile, "%u", &(USER.phone.phoneNum));
    for(i = 0; i < usrPerams.codeCnt; i++){
        fscanf(saveFile, "%s", strBuff);
        USER.ICD[i].codes = (char*)malloc(strlen(strBuff) * sizeof(char));
        strcpy(USER.ICD[i].codes, strBuff);
        memset(strBuff, 0, IN_BUFFER);
        spaceConv(USER.ICD[i].codes, 'S');
        fscanf(saveFile, "%u", &(USER.ICD[i].dates));
    }
    spaceConv(USER.fName, 'S');
    spaceConv(USER.lName, 'S');
    spaceConv(USER.street, 'S');
    spaceConv(USER.city, 'S');
}
void printInfo(){
    unsigned int i;
    printf("\n\nElectronic Medical Record for %s %s: ", USER.fName, USER.lName);
    printf("\n%hu %s", USER.addNum, USER.street);
    printf("\n%s, ", USER.city);
    switch(USER.stateEnum){
        case AL: printf("AL"); break;
        case AK: printf("AK"); break;
        case AZ: printf("AZ"); break;
        case AR: printf("AR"); break;
        case CA: printf("CA"); break;
        case CO: printf("CO"); break;
        case CT: printf("CT"); break;
        case DE: printf("DE"); break;
        case DC: printf("DC"); break;
        case FL: printf("FL"); break;
        case GA: printf("GA"); break;
        case HI: printf("HI"); break;
        case ID: printf("ID"); break;
        case IL: printf("IL"); break;
        case IN: printf("IN"); break;
        case IA: printf("IA"); break;
        case KS: printf("KS"); break;
        case KY: printf("KY"); break;
        case LA: printf("LA"); break;
        case ME: printf("ME"); break;
        case MD: printf("MD"); break;
        case MA: printf("MA"); break;
        case MI: printf("MI"); break;
        case MN: printf("MN"); break;
        case MS: printf("MS"); break;
        case MO: printf("MO"); break;
        case MT: printf("MT"); break;
        case NE: printf("NE"); break;
        case NV: printf("NV"); break;
        case NH: printf("NH"); break;
        case NJ: printf("NJ"); break;
        case NM: printf("NM"); break;
        case NY: printf("NY"); break;
        case NC: printf("NC"); break;
        case ND: printf("ND"); break;
        case OH: printf("OH"); break;
        case OK: printf("OK"); break;
        case OR: printf("OR"); break;
        case PA: printf("PA"); break;
        case RI: printf("RI"); break;
        case SC: printf("SC"); break;
        case SD: printf("SD"); break;
        case TN: printf("TN"); break;
        case TX: printf("TX"); break;
        case UT: printf("UT"); break;
        case VT: printf("VT"); break;
        case VA: printf("VA"); break;
        case WA: printf("WA"); break;
        case WV: printf("WV"); break;
        case WI: printf("WI"); break;
        case WY: printf("WY"); break;
    }
    printf(" %05u-%04hu", USER.zip, USER.plusFour);
    switch(USER.phone.pType){
        case WORK: printf("\nWork number: "); break;
        case CELL: printf("\nCell number: "); break;
        case HOME: printf("\nHome number: "); break;
    }
    printf("(%hu) %u-%u", USER.phone.areaCode, (USER.phone.phoneNum/10000), (USER.phone.phoneNum%10000));
    for(i = 0; i < usrPerams.codeCnt; i++){
        printf("\nICD%u: %s\tDate last modified: %02u/%02u/%04u", i+1, USER.ICD[i].codes, USER.ICD[i].dates/1000000, (USER.ICD[i].dates/10000)%100, USER.ICD[i].dates%10000);
    }
    printf("\n\n");
}
bool parcsePerams(int argc, char* argv[]){
    int i = 1;
    usrPerams.reload = false;
    usrPerams.codeCntChange = false;
    usrPerams.codeCnt = MAX_ICD_NUM;
    if(argc == 1){
        return true;
    }
    if(argc == 3){
        switch(argv[i][1]){
            case 'c': 
                usrPerams.codeCntChange = true;
                usrPerams.codeCnt = atoi(argv[i+1]);
                return true;
            case 'r': 
                usrPerams.reload = true; 
                usrPerams.fileName = (char*)malloc(strlen(argv[i+1])*sizeof(char)); 
                strcpy(usrPerams.fileName, argv[i+1]);
                return true;
            default:
                return false;
        }
    }
    return false;
}
void helpPage(){
    printf("\n---HELP PAGE---");
    printf("\n\nOptions:");
    printf("\n   -r {ICD_FILENAME}\treloads a given EMR file");
    printf("\n   -c {ICD_COUNT}\tallows the code to run with a given count of ICD codes");
    printf("\n\nThe flag options are exclusive and cannot be ran simultaneously\n\n");
}
int main(int argc, char* argv[]) {
    char strBuff[IN_BUFFER];
    if(!(parcsePerams(argc, argv))){
        helpPage();
        return 22;
    }
    USER.ICD = (struct ICD_INFO*)malloc(usrPerams.codeCnt * sizeof(struct ICD_INFO));
    if(usrPerams.reload){
        FILE* readICD = fopen(usrPerams.fileName, "r");
        if(readICD == NULL){
            printf("\nThe given file was not able to be open.\n\n");
            return 2;
        }
        retAllInfo(readICD, strBuff);
        fclose(readICD);
        free(usrPerams.fileName);
        printInfo(); 
        return 0;
    }
    unsigned int i;
    char userChar;
    bool errorFree = false;
    char* fileName = NULL;
    
    if(!(usrPerams.codeCntChange)){
        userChar = getYorN("Would you like to reload a previous EMR");
    }
    
    do{
        printf("\nPlease provide the patient's First Name: ");
        errorFree = getValidStr(strBuff, "First Name", MAX_FNAME_LEN);
    }while(!errorFree);
    USER.fName = (char*)malloc(strlen(strBuff) * sizeof(char));
    strcpy(USER.fName, strBuff);
    memset(strBuff, 0, IN_BUFFER);
    errorFree = false;

    /* error trap for last name */
    do{
        printf("\nPlease provide the patient's Last Name: ");
        errorFree = getValidStr(strBuff, "Last Name", MAX_LNAME_LEN);
    }while(!errorFree);
    USER.lName = (char*)malloc(strlen(strBuff) * sizeof(char));
    strcpy(USER.lName, strBuff);
    memset(strBuff, 0, IN_BUFFER);
    errorFree = false;

    if(userChar == 'Y'){
        USER.recNum = getRecNum();
        /* remove any extra new lines in the strings "\n" */
        if(isprint(USER.fName[strlen(USER.fName) - 1]) == 0){
            USER.fName[strlen(USER.fName)-1] = '\0';
        }
        if(isprint(USER.lName[strlen(USER.lName) - 1]) == 0){
            USER.lName[strlen(USER.lName)-1] = '\0';
        }
        getFileName(USER.fName, USER.lName, USER.recNum, strBuff);
        fileName = (char*)malloc(strlen(strBuff) * sizeof(char));
        strcpy(fileName, strBuff);
        memset(strBuff, 0, IN_BUFFER);
        FILE* readRequest = fopen(fileName, "r");
        if(readRequest == NULL){
            printf("\nFile \"%s\" could not be found or does not exist.\nIf you wish to try again, please re-run the program.\n", fileName);
            free(USER.fName);
            free(USER.lName);
            free(fileName);
            free(USER.ICD);
            fclose(readRequest);
            return 2;
        }
        else{
            retAllInfo(readRequest, strBuff);
            printInfo();
            fscanf(readRequest, "%s", strBuff);
            printf("\n%s", strBuff);
            free(USER.fName);
            free(USER.lName);
            free(fileName);
            free(USER.ICD);
            fclose(readRequest);
            return 0;
        }
    } /
    USER.addNum = getAdd();
    do{
        printf("\nPlease provide the patient's Street Name: ");
        errorFree = getValidStr(strBuff, "Street Name", MAX_STREET_LEN);
    }while(!errorFree);
    USER.street = (char*)malloc(strlen(strBuff) * sizeof(char));
    strcpy(USER.street, strBuff);
    memset(strBuff, 0, IN_BUFFER);
    errorFree = false;
    
   
    do{
        printf("\nPlease provide the patient's City Name: ");
        errorFree = getValidStr(strBuff, "City Name", MAX_CITY_LEN);
    }while(!errorFree);
    USER.city = (char*)malloc(strlen(strBuff) * sizeof(char));
    strcpy(USER.city, strBuff);
    memset(strBuff, 0, IN_BUFFER);
    errorFree = false;
    

    getState(strBuff);
    memset(strBuff, 0, IN_BUFFER);
    
    USER.zip = getZIPcode();
    
   
    USER.plusFour = getZIPplusFour();
   USER.phone.areaCode = getAreaCode();
    

    USER.phone.phoneNum = getPhoneNum();

    getPhoneType(strBuff);
    memset(strBuff, 0, IN_BUFFER);


    for(i = 0; i < usrPerams.codeCnt; i++){

        do{
            printf("\nPlease provide ICD code %u: ", i+1);
            errorFree = getValidStr(strBuff, "ICD Code", MAX_ICD_LEN);
        }while(!errorFree);
        USER.ICD[i].len = strlen(strBuff);
        USER.ICD[i].codes = (char*)malloc(USER.ICD[i].len * sizeof(char));
        strcpy(USER.ICD[i].codes, strBuff);
        memset(strBuff, 0, IN_BUFFER);
        errorFree = false;

        USER.ICD[i].dates = getICDdate(i);
    }

    
    if(isprint(USER.fName[strlen(USER.fName) - 1]) == 0){
        USER.fName[strlen(USER.fName)-1] = '\0';
    }
    if(isprint(USER.lName[strlen(USER.lName) - 1]) == 0){
        USER.lName[strlen(USER.lName)-1] = '\0';
    }
    if(isprint(USER.street[strlen(USER.street) - 1]) == 0){
        USER.street[strlen(USER.street)-1] = '\0';
    }
    if(isprint(USER.city[strlen(USER.city) - 1]) == 0){
        USER.city[strlen(USER.city)-1] = '\0';
    }
    for(i = 0; i < usrPerams.codeCnt; i++){
        if(isprint(USER.ICD[i].codes[strlen(USER.ICD[i].codes) - 1]) == 0){
            USER.ICD[i].codes[strlen(USER.ICD[i].codes)  - 1] = '\0';
        }
    }

    printInfo();
    userChar = getYorN("Would you like to save this EMR to a file");
    if(userChar == 'Y'){
        FILE* readICDptr = fopen("ICD.idx", "r");

        if(readICDptr == NULL){
            FILE* writeICDptr = fopen("ICD.idx", "w");
            USER.recNum = 1;
            fprintf(writeICDptr, "%u", USER.recNum);
            fclose(writeICDptr);
        }
        else{
            fscanf(readICDptr, "%u", &USER.recNum);
            fclose(readICDptr);
        }
        getFileName(USER.fName, USER.lName, USER.recNum, strBuff);
        fileName = (char*)malloc(strlen(strBuff) * sizeof(char));
        strcpy(fileName, strBuff);
        memset(strBuff, 0, IN_BUFFER);
        FILE* newEMR = fopen(fileName, "w");
        saveAllInfo(newEMR);
        printf("\nThe EMR created was saved to: %s\n\n", fileName);
        USER.recNum++;
        FILE* writeICDptr = fopen("ICD.idx", "w");
        fprintf(writeICDptr, "%u", USER.recNum);
        fclose(newEMR);
        fclose(writeICDptr);
    }
    else{
        printf("\nAll data entered will be erased from memory,\nSee you next time!\n\n");
    }
    free(USER.fName);
    free(USER.lName);
    free(USER.street);
    free(USER.city);
    for(i = 0; i < usrPerams.codeCnt; i++){
        free(USER.ICD[i].codes);
    }
    free(USER.ICD);
    return 0;
}
