#include <string>
using namespace std;

class Cert487{
    public:
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
};