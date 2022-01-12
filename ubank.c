#include <stdio.h>
#include <curl/curl.h>

void main ()
{
     CURL *curl;
     CURLcode response;

    curl_global_init(CURL_GLOBAL_ALL);

     curl = curl_easy_init();
   if(curl) {
    struct curl_slist *chunk = NULL;
    chunk = curl_slist_append(chunk, "Authorization: Bearer -tQ5LU7LRjaQMPJYpQw9VQVKOy18Iz0QOD_tafKogl4");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
    curl_easy_setopt(curl, CURLOPT_URL, "https://mstdn.social/api/v1/statuses");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "status=Mastodon API request from C!");
    response = curl_easy_perform(curl);
    if(response != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(response));
 
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return 0;
}