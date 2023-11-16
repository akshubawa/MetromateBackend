#include <bits/stdc++.h>
using namespace std;

class graph {
public:
  unordered_map<string, list<pair<string, string>>> adj;

  void addEdge(string u, string v, string line) {
    adj[u].push_back(make_pair(v, line));
    adj[v].push_back(make_pair(u, line));
  }

  bool hasPath(string source, string destination) {
    unordered_set<string> visited;
    queue<string> q;
    unordered_map<string, string> parent;

    visited.insert(source);
    q.push(source);

    while (!q.empty()) {
      string current = q.front();
      q.pop();

      if (current == destination) {
        vector<string> path;
        vector<string> lines;
        string node = destination;
        while (node != source) {
          path.push_back(node);

          for (const auto& neighbor : adj[node]) {
            if (neighbor.first == parent[node]) {
              lines.push_back(neighbor.second);
              break;
            }
          }
    
          node = parent[node];
        }
        path.push_back(source);

        cout << "SOURCE: " << source << endl;
        cout << "DESTINATION: " << destination << endl << endl;
        cout << "NUMBER OF STATIONS: " << path.size() << endl;

        int interchange_count=0;
        for (int i=0; i<lines.size()-1; i++) {
          if (lines[i]!=lines[i+1])
            interchange_count++;
        }
        cout << "NUMBER OF INTERCHANGES: " << interchange_count << endl;
        cout << "TIME: " << path.size() * 2.5 << " minutes" << endl << endl;

        cout << "PATH FROM " << source << " TO " << destination << ": " << endl << endl;
        for (int i = path.size() - 1; i >= 0; i--) {
          cout << path[i];
          if (i > 0)
            cout << "("<< lines[i-1] << ")" << endl;
        }
        cout << endl;

        return true;
      }

      for (auto neighbor : adj[current]) {
        string v = neighbor.first;
        if (visited.find(v) == visited.end()) {
          visited.insert(v);
          parent[v] = current;
          q.push(v);
        }
      }
    }

    cout << "No path found between " << source << " and " << destination << endl;
    return false;
  }
};

int main() {
  int m = 254;

  graph g;

  vector<vector<string>> data = {
    {"ARTHALA", "HINDON RIVER", "RED"},
    {"ARTHALA", "MOHAN NAGAR", "RED"},
    {"DILSHAD GARDEN", "SHAHEED NAGAR", "RED"},
    {"DILSHAD GARDEN", "JHILMIL", "RED"},
    {"HINDON RIVER", "SHAHEED STHAL(NEW BUS ADDA)", "RED"},
    {"INDERLOK", "KANHAIYA NAGAR", "RED"},
    {"INDERLOK", "SHASTRI NAGAR", "RED"},
    {"JHILMIL", "MANSAROVAR PARK", "RED"},
    {"KASHMERE GATE", "SHASTRI PARK", "RED"},
    {"KASHMERE GATE", "TIS HAZARI", "RED"},
    {"KANHAIYA NAGAR", "KESHAVPURAM", "RED"},
    {"KESHAVPURAM", "NETAJI SUBHASH PLACE", "RED"},
    {"KOHAT ENCLAVE", "NETAJI SUBHASH PLACE", "RED"},
    {"KOHAT ENCLAVE", "PITAMPURA", "RED"},
    {"MAJOR MOHIT SHARMA RAJENDRA NAGAR", "RAJ BAGH", "RED"},
    {"MAJOR MOHIT SHARMA RAJENDRA NAGAR", "SHYAM PARK", "RED"},
    {"MANSAROVAR PARK", "SHAHADRA", "RED"},
    {"MOHAN NAGAR", "SHYAM PARK", "RED"},
    {"PITAMPURA", "ROHINI EAST", "RED"},
    {"PRATAP NAGAR", "PULBANGASH", "RED"},
    {"PRATAP NAGAR", "SHASTRI NAGAR", "RED"},
    {"PULBANGASH", "TIS HAZARI", "RED"},
    {"RAJ BAGH", "SHAHEED NAGAR", "RED"},
    {"RITHALA", "ROHINI WEST", "RED"},
    {"ROHINI EAST", "ROHINI WEST", "RED"},
    {"SHAHADRA", "WELCOME", "RED"},
    {"SEELAMPUR", "SHASTRI PARK", "RED"},
    {"SEELAMPUR", "WELCOME", "RED"},
    {"LAL QUILA", "JAMA MASJID", "VIOLET"},
    {"JAMA MASJID", "DELHI GATE", "VIOLET"},
    {"DELHI GATE", "ITO", "VIOLET"},
    {"ITO", "MANDI HOUSE", "VIOLET"},
    {"MANDI HOUSE", "JANPATH", "VIOLET"},
    {"JANPATH", "CENTRAL SECRETARIAT", "VIOLET"},
    {"CENTRAL SECRETARIAT", "KHAN MARKET", "VIOLET"},
    {"KHAN MARKET", "JLN STADIUM", "VIOLET"},
    {"JLN STADIUM", "JANGPURA", "VIOLET"},
    {"JANGPURA", "LAJPAT NAGAR", "VIOLET"},
    {"LAJPAT NAGAR", "MOOLCHAND", "VIOLET"},
    {"MOOLCHAND", "KAILASH COLONY", "VIOLET"},
    {"KAILASH COLONY", "NEHRU PLACE", "VIOLET"},
    {"NEHRU PLACE", "KALKAJI MANDIR", "VIOLET"},
    {"KALKAJI MANDIR", "GOVIND PURI", "VIOLET"},
    {"GOVIND PURI", "HARKESH NAGAR OKHLA", "VIOLET"},
    {"HARKESH NAGAR OKHLA", "JASOLA APOLLO", "VIOLET"},
    {"JASOLA APOLLO", "SARITA VIHAR", "VIOLET"},
    {"SARITA VIHAR", "MOHAN ESTATE", "VIOLET"},
    {"MOHAN ESTATE", "TUGHLAKABAD STATION", "VIOLET"},
    {"TUGHLAKABAD STATION", "BADARPUR BORDER", "VIOLET"},
    {"BADARPUR BORDER", "SARAI", "VIOLET"},
    {"SARAI", "NHPC CHOWK", "VIOLET"},
    {"NHPC CHOWK", "MEWALA MAHARAJPUR", "VIOLET"},
    {"MEWALA MAHARAJPUR", "SECTOR 28", "VIOLET"},
    {"SECTOR 28", "BADKAL MOR", "VIOLET"},
    {"BADKAL MOR", "OLD FARIDABAD", "VIOLET"},
    {"OLD FARIDABAD", "NEELAM CHOWK AJRONDA", "VIOLET"},
    {"NEELAM CHOWK AJRONDA", "BATA CHOWK", "VIOLET"},
    {"BATA CHOWK", "ESCORTS MUJESAR", "VIOLET"},
    {"ESCORTS MUJESAR", "SANT SURDAS SIHAN", "VIOLET"},
    {"SANT SURDAS SIHAN", "Raja Nahar Singh", "VIOLET"},
    {"JANAK PURI WEST", "DABRI MOR - JANAKPURI SOUTH", "MAGENTA"},
    {"DABRI MOR - JANAKPURI SOUTH", "DASHRATHPURI", "MAGENTA"},
    {"DASHRATHPURI", "PALAM", "MAGENTA"},
    {"PALAM", "SADAR BAZAR CANTONMENT", "MAGENTA"},
    {"SADAR BAZAR CANTONMENT", "TERMINAL 1-IGI AIRPORT", "MAGENTA"},
    {"TERMINAL 1-IGI AIRPORT", "SHANKAR VIHAR", "MAGENTA"},
    {"SHANKAR VIHAR", "VASANT VIHAR", "MAGENTA"},
    {"VASANT VIHAR", "MUNIRKA", "MAGENTA"},
    {"MUNIRKA", "R.K. PURAM", "MAGENTA"},
    {"R.K. PURAM", "IIT", "MAGENTA"},
    {"IIT", "HAUZ KHAS", "MAGENTA"},
    {"HAUZ KHAS", "PANCHSHEEL PARK", "MAGENTA"},
    {"PANCHSHEEL PARK", "CHIRAG DELHI", "MAGENTA"},
    {"CHIRAG DELHI", "GREATER KAILASH", "MAGENTA"},
    {"GREATER KAILASH", "NEHRU ENCLAVE", "MAGENTA"},
    {"NEHRU ENCLAVE", "KALKAJI MANDIR", "MAGENTA"},
    {"KALKAJI MANDIR", "OKHLA NSIC", "MAGENTA"},
    {"OKHLA NSIC", "SUKHDEV VIHAR", "MAGENTA"},
    {"SUKHDEV VIHAR", "JAMIA MILIA ISLAMIYA", "MAGENTA"},
    {"JAMIA MILIA ISLAMIYA", "OKHLA VIHAR", "MAGENTA"},
    {"OKHLA VIHAR", "JASOLA VIHAR SHAHEEN BAGH", "MAGENTA"},
    {"JASOLA VIHAR SHAHEEN BAGH", "KALINDI KUNJ", "MAGENTA"},
    {"KALINDI KUNJ", "OKHLA BIRD SANCTUARY", "MAGENTA"},
    {"OKHLA BIRD SANCTUARY", "BOTANICAL GARDEN", "MAGENTA"},
    {"KIRTI NAGAR", "SATGURU RAM SINGH MARG", "GREEN"},
    {"SATGURU RAM SINGH MARG", "INDERLOK", "GREEN"},
    {"INDERLOK", "ASHOK NAGAR MAIN", "GREEN"},
    {"ASHOK NAGAR MAIN", "PUNJABI BAGH", "GREEN"},
    {"PUNJABI BAGH", "PUNJABI BAGH WEST", "GREEN"},
    {"PUNJABI BAGH WEST", "SHIVAJI PARK", "GREEN"},
    {"SHIVAJI PARK", "MADIPUR", "GREEN"},
    {"MADIPUR", "PASCHIM VIHAR EAST", "GREEN"},
    {"PASCHIM VIHAR EAST", "PASCHIM VIHAR WEST", "GREEN"},
    {"PASCHIM VIHAR WEST", "PEERAGARHI", "GREEN"},
    {"PEERAGARHI", "UDYOG NAGAR", "GREEN"},
    {"UDYOG NAGAR", "MAHARAJA SURAJMAL STADIUM", "GREEN"},
    {"MAHARAJA SURAJMAL STADIUM", "NANGLOI", "GREEN"},
    {"NANGLOI", "NANGLOI RAILWAY STATION", "GREEN"},
    {"NANGLOI RAILWAY STATION", "RAJDHANI PARK", "GREEN"},
    {"RAJDHANI PARK", "MUNDKA", "GREEN"},
    {"MUNDKA", "MUNDKA INDUSTRIAL AREA (MIA)", "GREEN"},
    {"MUNDKA INDUSTRIAL AREA (MIA)", "GHEVRA METRO STATION", "GREEN"},
    {"GHEVRA METRO STATION", "TIKRI KALAN", "GREEN"},
    {"TIKRI KALAN", "TIKRI BORDER", "GREEN"},
    {"TIKRI BORDER", "PANDIT SHREE RAM SHARMA", "GREEN"},
    {"PANDIT SHREE RAM SHARMA", "BAHADURGARH CITY", "GREEN"},
    {"BAHADURGARH CITY", "BRIG HOSHIYAR SINGH", "GREEN"},
    {"NEW DELHI (YELLOW & AIRPORT LINE)", "SHIVAJI STADIUM", "ORANGE"},
    {"SHIVAJI STADIUM", "DHAULA KUAN", "ORANGE"},
    {"DHAULA KUAN", "DELHI AEROCITY", "ORANGE"},
    {"DELHI AEROCITY", "AIRPORT (T3)", "ORANGE"},
    {"AIRPORT (T3)", "DWARKA SECTOR 21", "ORANGE"},
    {"DWARKA SECTOR 21", "YASHOBHOOMI DWARKA SECTOR 25", "ORANGE"},
    {"DWARKA SECTOR 21", "DWARKA SECTOR 8", "BLUE"},
    {"DWARKA SECTOR 8", "DWARKA SECTOR 9", "BLUE"},
    {"DWARKA SECTOR 9", "DWARKA SECTOR 10", "BLUE"},
    {"DWARKA SECTOR 10", "DWARKA SECTOR 11", "BLUE"},
    {"DWARKA SECTOR 11", "DWARKA SECTOR 12", "BLUE"},
    {"DWARKA SECTOR 12", "DWARKA SECTOR 13", "BLUE"},
    {"DWARKA SECTOR 13", "DWARKA SECTOR 14", "BLUE"},
    {"DWARKA SECTOR 14", "DWARKA", "BLUE"},
    {"DWARKA", "DWARKA MOR", "BLUE"},
    {"DWARKA MOR", "NAWADA", "BLUE"},
    {"NAWADA", "UTTAM NAGAR WEST", "BLUE"},
    {"UTTAM NAGAR WEST", "UTTAM NAGAR EAST", "BLUE"},
    {"UTTAM NAGAR EAST", "JANAK PURI WEST", "BLUE"},
    {"JANAK PURI WEST", "JANAK PURI EAST", "BLUE"},
    {"JANAK PURI EAST", "TILAK NAGAR", "BLUE"},
    {"TILAK NAGAR", "SUBHASH NAGAR", "BLUE"},
    {"SUBHASH NAGAR", "TAGORE GARDEN", "BLUE"},
    {"TAGORE GARDEN", "RAJOURI GARDEN", "BLUE"},
    {"RAJOURI GARDEN", "RAMESH NAGAR", "BLUE"},
    {"RAMESH NAGAR", "MOTI NAGAR", "BLUE"},
    {"MOTI NAGAR", "KIRTI NAGAR", "BLUE"},
    {"KIRTI NAGAR", "SHADIPUR", "BLUE"},
    {"SHADIPUR", "PATEL NAGAR", "BLUE"},
    {"PATEL NAGAR", "RAJENDRA PLACE", "BLUE"},
    {"RAJENDRA PLACE", "KAROL BAGH", "BLUE"},
    {"KAROL BAGH", "JHANDEWALAN", "BLUE"},
    {"JHANDEWALAN", "RAMAKRISHNA ASHRAM MARG", "BLUE"},
    {"RAMAKRISHNA ASHRAM MARG", "RAJIV CHOWK", "BLUE"},
    {"RAJIV CHOWK", "BARAKHAMBA ROAD", "BLUE"},
    {"BARAKHAMBA ROAD", "MANDI HOUSE", "BLUE"},
    {"MANDI HOUSE", "SUPREME COURT", "BLUE"},
    {"SUPREME COURT", "INDRAPRASTHA", "BLUE"},
    {"INDRAPRASTHA", "YAMUNA BANK", "BLUE"},
    {"YAMUNA BANK", "AKSHARDHAM", "BLUE"},
    {"AKSHARDHAM", "MAYUR VIHAR 1", "BLUE"},
    {"MAYUR VIHAR 1", "MAYUR VIHAR EXTENSION", "BLUE"},
    {"MAYUR VIHAR EXTENSION", "NEW ASHOK NAGAR", "BLUE"},
    {"NEW ASHOK NAGAR", "NOIDA SECTOR 15", "BLUE"},
    {"NOIDA SECTOR 15", "NOIDA SECTOR 16", "BLUE"},
    {"NOIDA SECTOR 16", "NOIDA SECTOR 18", "BLUE"},
    {"NOIDA SECTOR 18", "BOTANICAL GARDEN", "BLUE"},
    {"BOTANICAL GARDEN", "GOLF COURSE", "BLUE"},
    {"GOLF COURSE", "NOIDA CITY CENTRE", "BLUE"},
    {"NOIDA CITY CENTRE", "NOIDA SECTOR 34", "BLUE"},
    {"NOIDA SECTOR 34", "NOIDA SECTOR 52", "BLUE"},
    {"NOIDA SECTOR 52", "NOIDA SECTOR 61", "BLUE"},
    {"NOIDA SECTOR 61", "NOIDA SECTOR 59", "BLUE"},
    {"NOIDA SECTOR 59", "NOIDA SECTOR 62", "BLUE"},
    {"NOIDA SECTOR 62", "NOIDA ELECTRONIC CITY", "BLUE"},
    {"YAMUNA BANK", "LAXMI NAGAR", "BLUE 2"},
    {"LAXMI NAGAR", "NIRMAN VIHAR", "BLUE 2"},
    {"NIRMAN VIHAR", "PREET VIHAR", "BLUE 2"},
    {"PREET VIHAR", "KARKARDUMA", "BLUE 2"},
    {"KARKARDUMA", "ANAND VIHAR ISBT", "BLUE 2"},
    {"ANAND VIHAR ISBT", "KAUSHAMBI", "BLUE 2"},
    {"KAUSHAMBI", "VAISHALI", "BLUE 2"},
    {"MAJLIS PARK", "AZADPUR", "PINK"},
    {"AZADPUR", "SHALIMAR BAGH", "PINK"},
    {"SHALIMAR BAGH", "NETAJI SUBHASH PALACE", "PINK"},
    {"NETAJI SUBHASH PALACE", "SHAKURPUR", "PINK"},
    {"SHAKURPUR", "PUNJABI BAGH WEST", "PINK"},
    {"PUNJABI BAGH WEST", "ESI BASAIDARAPUR", "PINK"},
    {"ESI BASAIDARAPUR", "RAJOURI GARDEN", "PINK"},
    {"RAJOURI GARDEN", "MAYAPURI", "PINK"},
    {"MAYAPURI", "NARAINA VIHAR", "PINK"},
    {"NARAINA VIHAR", "DELHI CANTT", "PINK"},
    {"DELHI CANTT", "DURGABAI DESHMUKH SOUTH CAMPUS", "PINK"},
    {"DURGABAI DESHMUKH SOUTH CAMPUS", "SIR M VISHESHWARAIAH MOTI BAGH", "PINK"},
    {"SIR M VISHESHWARAIAH MOTI BAGH", "BHIKAJI CAMA PLACE", "PINK"},
    {"BHIKAJI CAMA PLACE", "SAROJINI NAGAR", "PINK"},
    {"SAROJINI NAGAR", "DILLI HAAT INA", "PINK"},
    {"DILLI HAAT INA", "SOUTH EXTENSION", "PINK"},
    {"SOUTH EXTENSION", "LAJPAT NAGAR", "PINK"},
    {"LAJPAT NAGAR", "VINOBAPURI", "PINK"},
    {"VINOBAPURI", "ASHRAM", "PINK"},
    {"ASHRAM", "SARAI KALE KHAN NIZAMUDDIN", "PINK"},
    {"SARAI KALE KHAN NIZAMUDDIN", "MAYUR VIHAR 1", "PINK"},
    {"MAYUR VIHAR 1", "MAYUR VIHAR POCKET 1", "PINK"},
    {"MAYUR VIHAR POCKET 1", "TRILOKPURI SANJAY LAKE", "PINK"},
    {"TRILOKPURI SANJAY LAKE", "EAST VINOD NAGAR MAYUR VIHAR 2", "PINK"},
    {"EAST VINOD NAGAR MAYUR VIHAR 2", "MANDAWALI WEST VINOD NAGAR", "PINK"},
    {"MANDAWALI WEST VINOD NAGAR", "IP EXTENSION", "PINK"},
    {"IP EXTENSION", "ANAND VIHAR ISBT", "PINK"},
    {"ANAND VIHAR ISBT", "KARKARDUMA", "PINK"},
    {"KARKARDUMA", "KARKARDUMA COURT", "PINK"},
    {"KARKARDUMA COURT", "KRISHNA NAGAR", "PINK"},
    {"KRISHNA NAGAR", "EAST AZAD NAGAR", "PINK"},
    {"EAST AZAD NAGAR", "WELCOME", "PINK"},
    {"WELCOME", "JAFRABAD", "PINK"},
    {"JAFRABAD", "MAUJPUR BABARPUR", "PINK"},
    {"MAUJPUR BABARPUR", "GOKULPURI", "PINK"},
    {"GOKULPURI", "KOHRI ENCLAVE", "PINK"},
    {"KOHRI ENCLAVE", "SHIV VIHAR", "PINK"},
    {"ROHINI SECTOR 18 19", "HAIDERPUR BADLI MOR", "YELLOW"},
    {"HAIDERPUR BADLI MOR", "JAHANGIRPURI", "YELLOW"},
    {"JAHANGIRPURI", "ADARSH NAGAR", "YELLOW"},
    {"ADARSH NAGAR", "AZADPUR", "YELLOW"},
    {"AZADPUR", "MODEL TOWN", "YELLOW"},
    {"MODEL TOWN", "GURU TEG BAHADUR NAGAR", "YELLOW"},
    {"GURU TEG BAHADUR NAGAR", "VISHWAVIDYALAYA", "YELLOW"},
    {"VISHWAVIDYALAYA", "VIDHAN SABHA", "YELLOW"},
    {"VIDHAN SABHA", "CIVIL LINES", "YELLOW"},
    {"CIVIL LINES", "KASHMERE GATE", "YELLOW"},
    {"KASHMERE GATE", "CHANDNI CHOWK", "YELLOW"},
    {"CHANDNI CHOWK", "CHAWRI BAZAR", "YELLOW"},
    {"CHAWRI BAZAR", "NEW DELHI", "YELLOW"},
    {"NEW DELHI", "RAJIV CHOWK", "YELLOW"},
    {"RAJIV CHOWK", "PATEL CHOWK", "YELLOW"},
    {"PATEL CHOWK", "CENTRAL SECRETARIAT", "YELLOW"},
    {"CENTRAL SECRETARIAT", "UDYOG BHAWAN", "YELLOW"},
    {"UDYOG BHAWAN", "LOK KALYAN MARG", "YELLOW"},
    {"LOK KALYAN MARG", "JOR BAGH", "YELLOW"},
    {"JOR BAGH", "DILLI HAAT INA", "YELLOW"},
    {"DILLI HAAT INA", "AIIMS", "YELLOW"},
    {"AIIMS", "GREEN PARK", "YELLOW"},
    {"GREEN PARK", "HAUZ KHAS", "YELLOW"},
    {"HAUZ KHAS", "MALVIYA NAGAR", "YELLOW"},
    {"MALVIYA NAGAR", "SAKET", "YELLOW"},
    {"SAKET", "QUTAB MINAR", "YELLOW"},
    {"QUTAB MINAR", "CHHATARPUR", "YELLOW"},
    {"CHHATARPUR", "SULTANPUR", "YELLOW"},
    {"SULTANPUR", "GHITORNI", "YELLOW"},
    {"GHITORNI", "ARJAN GARH", "YELLOW"},
    {"ARJAN GARH", "GURU DRONACHARYA", "YELLOW"},
    {"GURU DRONACHARYA", "SIKANDERPUR", "YELLOW"},
    {"SIKANDERPUR", "MG ROAD", "YELLOW"},
    {"MG ROAD", "IFFCO CHOWK", "YELLOW"},
    {"IFFCO CHOWK", "MILLENIUM CITY CENTRE GURUGRAM", "YELLOW"},
    {"DWARKA", "NANGLI", "GREY"},
    {"NANGLI", "NAJFGARH", "GREY"},
    {"NAJFGARH", "DHANSA BUS STAND", "GREY"},
    {"SECTOR 55 56", "SECTOR 54 CHOWK", "RAPID"},
    {"SECTOR 54 CHOWK", "SECTOR 53 54", "RAPID"},
    {"SECTOR 53 54", "SECTOR 42 43", "RAPID"},
    {"SECTOR 42 43", "PHASE 1", "RAPID"},
    {"PHASE 1", "SIKANDERPUR", "RAPID"},
    {"SIKANDERPUR", "PHASE 2", "RAPID"},
    {"PHASE 2", "BELVEDERE TOWERS", "RAPID"},
    {"BELVEDERE TOWERS", "CYBER CITY", "RAPID"},
    {"CYBER CITY", "MOULSARI AVENUE", "RAPID"},
    {"MOULSARI AVENUE", "PHASE 3", "RAPID"}
    };

  for (int i=0; i<m; i++) {
    g.addEdge(data[i][0],data[i][1],data[i][2]);
  }

  string source, destination;
  cout << "Enter Source: ";
  getline(cin, source);
  transform(source.begin(), source.end(), source.begin(), ::toupper);

  cout << "Enter Destination: ";
  getline(cin, destination);
  transform(destination.begin(), destination.end(), destination.begin(), ::toupper);

  g.hasPath(source, destination);

  return 0;
}