// CTF{123_http_m3}
#include <curl/curl.h>
#include <openssl/md5.h>
#include <stdio.h>
#include <string.h>

#define FLAG "60aa9030c3a95d69c31f40f9754a9c8e"

size_t write_callback(void *contents, size_t size, size_t nmemb, char *output) {
  size_t realsize = size * nmemb;
  strncat(output, (char *)contents, realsize);
  return realsize;
}

void calculate_md5(const char *input, unsigned char *hash) {
  MD5_CTX md5;
  MD5_Init(&md5);
  MD5_Update(&md5, input, strlen(input));
  MD5_Final(hash, &md5);
}

int main() {
  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();

  if (curl) {
    char received_data[1000] =
        ""; // Adjust the size based on your expected data size

    char URL[60] = "";
    URL[59] = '/';
    URL[58] = 'g';
    URL[57] = '4';
    URL[56] = 'l';
    URL[55] = 'f';
    URL[54] = 't';
    URL[53] = '3';
    URL[52] = 'r';
    URL[51] = 'c';
    URL[50] = '3';
    URL[49] = 's';
    URL[48] = 'r';
    URL[47] = 'e';
    URL[46] = 'p';
    URL[45] = 'u';
    URL[44] = 's';
    URL[43] = '/';
    URL[42] = 'b';
    URL[41] = 'u';
    URL[40] = 'l';
    URL[39] = 'c';
    URL[38] = '.';
    URL[37] = 'f';
    URL[36] = 't';
    URL[35] = 'c';
    URL[34] = '-';
    URL[33] = 'u';
    URL[32] = 'e';
    URL[31] = 'n';
    URL[30] = '.';
    URL[29] = 's';
    URL[28] = 'e';
    URL[27] = 'g';
    URL[26] = 'n';
    URL[25] = 'e';
    URL[24] = 'l';
    URL[23] = 'l';
    URL[22] = 'a';
    URL[21] = 'h';
    URL[20] = 'c';
    URL[19] = '.';
    URL[18] = 'm';
    URL[17] = 'g';
    URL[16] = '.';
    URL[15] = '3';
    URL[14] = '1';
    URL[13] = '3';
    URL[12] = '0';
    URL[11] = '4';
    URL[10] = '2';
    URL[9] = '0';
    URL[8] = '2';
    URL[7] = '/';
    URL[6] = '/';
    URL[5] = ':';
    URL[4] = 's';
    URL[3] = 'p';
    URL[2] = 't';
    URL[1] = 't';
    URL[0] = 'h';

    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, received_data);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
      printf("bruh\n");
    } else {
      // Calculate MD5 hash of the received data
      unsigned char received_data_hash[MD5_DIGEST_LENGTH];
      calculate_md5(received_data, received_data_hash);

      // Check if the hashes match
      if (memcmp(FLAG, received_data_hash, MD5_DIGEST_LENGTH) == 0) {
        printf("Flag obtained!\n");
      } else {
        printf("FAILURE!\n");
      }
    }

    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();
  return 0;
}
