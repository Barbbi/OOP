#include <stdio.h>
#include <string.h>
#define MAX_MOVIES 30
#define MAX_SERVICES 10

typedef struct Movie{
    char name[100];
    float rating;
    char genre[40];
} Movie;

typedef struct StreamingService{
    char name[50];
    Movie movies[MAX_MOVIES];
    int numMovies;
} StreamingService;

void print(StreamingService* service) {
    printf("%s\n", service->name);
    for (int i = 0; i < service->numMovies; i++) {
        printf("%s %.1f\n", service->movies[i].name, service->movies[i].rating);
    }
}

void showBestStreamingService(StreamingService services[], int numServices, char genre[]) {
    int maxMovies = 0;
    int bestServiceIndex = -1;
    for (int i = 0; i < numServices; i++) {
        int numMoviesInGenre = 0;
        for (int j = 0; j < services[i].numMovies; j++) {
            if (strcmp(services[i].movies[j].genre, genre) == 0) {
                numMoviesInGenre++;
            }
        }
        if (numMoviesInGenre > maxMovies) {
            maxMovies = numMoviesInGenre;
            bestServiceIndex = i;
        }
    }
    if (bestServiceIndex >= 0) {
        printf("Best streaming service is: %s\n", services[bestServiceIndex].name);
    }
    else {
        printf("No service has movies of the given genre.\n");
    }
}

int main() {
    int num_services;
    scanf("%d", &num_services);
    StreamingService services[MAX_SERVICES];
    
    //read streaming services
    for (int i = 0; i < num_services; i++) {
        scanf("%s", services[i].name);
        int num_movies;
        scanf("%d", &num_movies);
        services[i].numMovies = num_movies;
        for (int j = 0; j < num_movies; j++) {
            scanf("%s %f %s", services[i].movies[j].name, &services[i].movies[j].rating, services[i].movies[j].genre);
        }
    }
    //print
    for (int i = 0; i < num_services; i++) {
        print(&services[i]);
    }
    //call to best streaming service
    char genre[40];
    scanf("%s", genre);
    showBestStreamingService(services, num_services, genre);

    return 0;
}
