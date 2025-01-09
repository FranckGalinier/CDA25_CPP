#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
using namespace std;

using json = nlohmann::json;

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    string readBuffer;
    string apiKey = "    07d6008d-338b-4bb9-a228-7b253ec29914";

    curl = curl_easy_init();

    if(curl) {
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("Authorization: " + apiKey).c_str());
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, "https://api.balldontlie.io/v1/teams");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Exécuter la requête
        res = curl_easy_perform(curl);

        // Vérifier le code de statut HTTP
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

        if (res != CURLE_OK) {
            cerr << "Error: " << curl_easy_strerror(res) << endl;
        } else if (http_code != 200) {
            cerr << "Error: HTTP request failed with code " << http_code << endl;
        } else {
            // Vérifier si la réponse est du JSON
            char* content_type;
            curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &content_type);
            if (content_type && strncmp(content_type, "application/json", 16) == 0) {
                cout << "Response is JSON" << endl;

                // Tenter de parser la réponse JSON
                try {
                    json response = json::parse(readBuffer);
                    cout << "Response JSON: " << response.dump(4) << endl;

                    // Exemple d'affichage des noms des équipes (ajustez selon la structure de la réponse)
                    for (const auto& team : response["data"]) {
                        cout << team["full_name"] << endl;
                    }
                } catch (const json::exception& e) {
                    cerr << "Error parsing JSON: " << e.what() << endl;
                }
            } else {
                cerr << "Expected JSON response, but got: " << (content_type ? content_type : "none") << endl;
            }
        }

        // Libérer les ressources
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    return 0;
}