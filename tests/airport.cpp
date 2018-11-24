#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define maxSizeAirportVector 12

using namespace std;

struct flight{
    int indexDestination;
    string numFlight;
    struct flight*next = NULL;
};

typedef struct flight Flight;

char printTxt[150];

class Airport
{
    private:
    string city;
    string codAirport;
    Flight *destination = NULL;

    public:
    void setCity(string name)
    {
        city = name;
    }
    string getCity()
    {
        return city;
    }

    void setCodAirport(string code)
    {
        codAirport = code;
    }

    string getCodAirport()
    {
        return codAirport;
    }

    Flight *getDestination()
    {
        return destination;
    }
    void setDestination(Flight* flight)
    {
        destination = flight;
    }
};


class AirportList
{
    private:
    Airport airports[maxSizeAirportVector];
    int sizeIndexAirport = 0;

    public:
    void registerAirport(string city, string codAirport);
    Airport getAirport(int indexAirport);
    void registerFlight(string numFlight, string codAirportDepart, string codAirportDestination);
    void viewFlightsAirport(string codAirport);
    void viewAllFlights();
    void removeFlight(string numFlight);

    int getSizeIndexAirport()
    {
        return sizeIndexAirport;
    }
};

void AirportList::registerAirport(string city, string codAirport)
{
    Airport airport;
    bool isValueRepeated = false;
    string print = "";

    if(sizeIndexAirport < maxSizeAirportVector)
    {
        for(int i = 0; i < sizeIndexAirport; i++)
        {
            if(airports[i].getCity() == city)
            {
                isValueRepeated = true;
                print = "Airport registration not done, because the city is already registered.\n\n";
                strcat(printTxt, print.c_str());
                cout << print << endl;
                break;
            }
            if(airports[i].getCodAirport() == codAirport)
            {
                isValueRepeated = true;
                print = "Airport registration not done, because the airport code already exists.\n\n";
                strcat(printTxt, print.c_str());
                cout << print << endl;
                break;
            }
        }
        if(!isValueRepeated)
        {
            airport.setCity(city);
            airport.setCodAirport(codAirport);
            airports[sizeIndexAirport] = airport;
            sizeIndexAirport++;
            print = "Airport registration successfully completed.\n\n";
            strcat(printTxt, print.c_str());
            cout << print << endl;
        }
    }
    else
    {
        print = "The vector already contains 12 elements\n\n";
        strcat(printTxt, print.c_str());
        cout << print << endl;
    }
}

void AirportList::registerFlight(string numFlight, string codAirportDepart, string codAirportDestination)
{
    bool departExist = false;
    bool destinationExist = false;
    int indexAirportDepart;
    int indexAirportDestination;
    string print;

    for(int i = 0; i < getSizeIndexAirport(); i++)
    {
        if(airports[i].getCodAirport() == codAirportDepart)
        {
            departExist = true;
            indexAirportDepart = i;
        }
        if(airports[i].getCodAirport() == codAirportDestination)
        {
            destinationExist = true;
            indexAirportDestination = i;
        }
    }

    if(!departExist && !destinationExist)
    {
        print = "The city of departure and the city of destination do not exist.\n\n";
        strcat(printTxt, print.c_str());
        cout << print << endl;
    }
    else
    {
        if(!departExist)
        {
            print = "The city of departure do not exist.\n\n";
            strcat(printTxt, print.c_str());
            cout << print << endl;
        }
        if(!destinationExist)
        {
            print = "The city of destination do not exist.\n\n";
            strcat(printTxt, print.c_str());
            cout << print << endl;
        }
    }

    if(departExist && destinationExist)
    {
        flight *current = NULL;
        for (current = airports[indexAirportDepart].getDestination(); current != NULL; current = current->next)
        {
            if(current->indexDestination == indexAirportDestination)
            {
                print = "This route is already covered by a flight!\n\n";
                strcat(printTxt, print.c_str());
                cout << print << endl;
                return;
            }
        }

        for(int i = 0; i < getSizeIndexAirport(); i++)
        {
            for (current = airports[i].getDestination(); current != NULL; current = current->next)
            {
                if(current->numFlight == numFlight)
                {
                    print = "The chosen flight number already exists, enter another!\n\n";
                    strcat(printTxt, print.c_str());
                    cout << print << endl;
                    return;
                }
            }
        }

        Flight* newFlight = new Flight();
        newFlight->indexDestination = indexAirportDestination;
        newFlight->numFlight = numFlight;
        newFlight->next = airports[indexAirportDepart].getDestination();
        airports[indexAirportDepart].setDestination(newFlight);

        print = "Flight registration successfully completed.\n\n";
        strcat(printTxt, print.c_str());
        cout << print << endl;
    }
}

Airport AirportList::getAirport(int indexAirport)
{
    return airports[indexAirport];
}

void AirportList::removeFlight(string numFlight){
    Flight *current = NULL;
    Flight *previous = NULL;
    int indexAirport;
    string print = "";

    for(int i = 0; i < getSizeIndexAirport(); i++)
    {
        current = airports[i].getDestination();
        if(current != NULL)
        {
            if(current != NULL && current->numFlight == numFlight)
            {
                indexAirport = i;
                previous = NULL;
            }

            for (current; current != NULL && current->numFlight != numFlight; current = current->next)
            {
                previous = current;
            }

            if(previous!=NULL)
            {
                if(previous->next!=NULL)
                {
                    if(previous->next->numFlight == numFlight)
                    {
                        Flight *lixo;
                        lixo = previous->next;
                        previous->next = lixo->next;
                        print = "Flight " + numFlight + ", removed.\n\n";
                        strcat(printTxt, print.c_str());
                        cout << print << endl;
                        free (lixo);
                        return;
                    }
                }
            }
            else
            {
                airports[indexAirport].setDestination(airports[indexAirport].getDestination()->next);
                print = "Flight " + numFlight + ", removed.\n\n";
                strcat(printTxt, print.c_str());
                cout << print << endl;
                return;
            }
        }
    }
    print = "The flight number " + numFlight + ", does not exist.\n\n";
    strcat(printTxt, print.c_str());
    cout << print << endl;
}

void AirportList::viewAllFlights(){
    Flight *current = NULL;
    int countFlights = 0;
    string print;

    for(int i = 0; i < getSizeIndexAirport(); i++)
    {
        for (current = airports[i].getDestination(); current != NULL; current = current->next)
        {
            print = "Flight number: " + current->numFlight + "; City depart: " + airports[i].getCity() + "; City destination: " + airports[current->indexDestination].getCity() + "\n";
            strcat(printTxt, print.c_str());
            cout << print << endl;
            countFlights++;
        }
    }
    if(countFlights <= 0)
    {
        print = "There are no flights to show.\n\n";
        strcat(printTxt, print.c_str());
        cout << print << endl;
    }
    else
    {
        print="\nComplete execution!\n\n";
        strcat(printTxt, print.c_str());
        cout << print << endl;
    }
}

void AirportList::viewFlightsAirport(string codAirport) {
    int indexAirport = 13;
    string print;

    for(int i = 0; i < getSizeIndexAirport(); i++)
    {
        if(airports[i].getCodAirport() == codAirport)
        {
            indexAirport = i;
            break;
        }
    }
    if(indexAirport < 13)
    {
        Flight *current = airports[indexAirport].getDestination();
        if(current!=NULL)
        {
            for(current; current != NULL; current = current->next)
            {
                print = "Flight number: " + current->numFlight + "; City destination: " + airports[current->indexDestination].getCity() + "\n";
                strcat(printTxt, print.c_str());
                cout << print << endl;
            }
        }
        else
        {
            print = "The airport does not have registered flights.\n\n";
            strcat(printTxt, print.c_str());
            cout << print << endl;
        }
    }
    else
    {
        print = "Airport code invalid.\n\n";
        strcat(printTxt, print.c_str());
        cout << print << endl;
    }
}

void printFlightsAirport (Flight *lista) {
   Flight *current;
   for (current = lista; current != NULL; current = current->next)
   {
      printf ("%d   ", current->indexDestination);
   }
   printf ("\n\n");
}

int main()
{
    AirportList airportList;
    string city, codAirport1, codAirport2, numFlight;

    airportList.registerAirport("Belo Horizonte", "PLU");
    airportList.registerAirport("Vitória", "VIX");
    airportList.registerAirport("São Paulo", "GRU");
    airportList.registerAirport("Rio de Janeiro", "SDU");
    airportList.registerAirport("Curitiba", "CWB");
    airportList.registerAirport("Porto Alegre", "POA");
    airportList.registerAirport("Florianópolis", "FLN");

    airportList.registerFlight("0024","PLU", "VIX");
    airportList.registerFlight("1489","PLU", "GRU");

    airportList.registerFlight("5736","VIX", "SDU");

    airportList.registerFlight("5487","GRU", "SDU");
    airportList.registerFlight("3452","GRU", "CWB");
    airportList.registerFlight("7545","GRU", "POA");

    airportList.registerFlight("3456","SDU", "PLU");
    airportList.registerFlight("1278","SDU", "GRU");

    airportList.registerFlight("4238","CWB", "GRU");
    airportList.registerFlight("1700","CWB", "FLN");

    airportList.registerFlight("2181","POA", "GRU");
    airportList.registerFlight("3004","POA", "CWB");

    airportList.registerFlight("6300","FLN", "SDU");


    int opcao = 1;

    while(opcao!=0)
    {

    FILE *arquivoTxt;
    arquivoTxt=fopen("output.txt","w+");
    fprintf(arquivoTxt,"%s",printTxt);
    fclose(arquivoTxt);


        printf ("\n\nChoose an option:\n");
        printf ("1. Register new airport.\n");
        printf ("2. Register flight.\n");
        printf ("3. Remove flight.\n");
        printf ("4. View all registered flights.\n");
        printf ("5. View all registered flights from an airport.\n");
        printf ("0. Enter 0 (zero) to exit.\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
            case 0 :
            break;

            case 1 :
            printf ("\nEnter the city to be registered:\n");
            cin >> city;
            printf ("\nEnter the airport code:\n");
            cin >> codAirport1;
            printf ("\n");
            airportList.registerAirport(city, codAirport1);
            break;

            case 2 :
            printf ("\nEnter the number of the flight to be registered:\n");
            cin >> numFlight;
            printf("\nEnter the departure airport code:\n");
            cin>> codAirport1;
            printf("\nEnter the destination airport code:\n");
            cin>> codAirport2;
            printf ("\n");
            airportList.registerFlight(numFlight, codAirport1, codAirport2);
            break;

            case 3 :
            printf ("\nEnter the number of the flight to be removed:\n");
            cin >> numFlight;
            printf ("\n");
            airportList.removeFlight(numFlight);
            break;

            case 4 :
            printf ("\n");
            airportList.viewAllFlights();
            break;

            case 5 :
            printf ("\nEnter the airport code:\n");
            cin >> codAirport1;
            printf ("\n");
            airportList.viewFlightsAirport(codAirport1);
            break;

            default :
            printf ("\nInvalid option!\n");
        }
    }

    return 0;
}
