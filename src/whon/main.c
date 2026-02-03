#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

int checkArguments(int argc, char *argv[]) {
	const char *platform_options[] = {"Twitch", "Discord"};
	
	if (argc < 3) {
		printf("ERROR: Needed arguments - <platform> <token> \n");
		exit(EXIT_FAILURE);
	}
	for (int i=0; i<sizeof(*platform_options)/sizeof(*(*(platform_options)); i++) {
		if (!strcmp(argv[1], platform_options[i])) {
			
		}
	}
	
	return 0;
}

int checkTwitch() {
	CURL *curl;

	CURLcode result = curl_global_init(CURL_GLOBAL_ALL);
	if (result)	return (int)result;
	
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		result = curl_easy_perform(curl);
		if (result != CURLM_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result));
		}

		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();

	return 0;
}


int main(int argc, char *argv[]) {

	if (!checkArguments(argc, argv)) {
		checkTwitch();
	}

	return 0;
}

