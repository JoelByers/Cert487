#include <string>
using namespace std;

class Cert487{
    private:
        int version;
        int serialNumber;
        string signatureAlgorithmIdentity;
        string signatureAlgorithmParameters;
        string issuerName;
        int validNotBefore;
        int validNotAfter;
        string subjectName;
        string publicKeyAlgorithm;
        string publicKeyParameters;
        int publicKey;
        string issuerUniqueIdentifier;
        string extensions;
        string signatureAlgorithm;
        string signatureParameters;
        string signature;
        void printLine(string label, string data);
        void parseCertLine(string input, string output[2]);
        void writeLineToFile(ofstream &fileOut, string label, string data);
    public:
        Cert487(string fileName);
        void print();
        void writeToFile(string fileName);
};