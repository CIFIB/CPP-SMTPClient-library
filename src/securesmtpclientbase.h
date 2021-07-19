#ifndef SECURESMTPCLIENTBASE_H
#define SECURESMTPCLIENTBASE_H

#include "smtpclientbase.h"
#include <openssl/ssl.h>

#ifdef _WIN32
	#ifdef SMTPCLIENT_EXPORTS  
		#define SECURESMTPCLIENTBASE_API __declspec(dllexport)   
	#else  
		#define SECURESMTPCLIENTBASE_API __declspec(dllimport)   
	#endif  
#else
	#define SECURESMTPCLIENTBASE_API
#endif

namespace jed_utils
{
	class SECURESMTPCLIENTBASE_API SecureSmtpClientBase : public SmtpClientBase
	{
	public:
    	SecureSmtpClientBase(const char *pServerName, unsigned int pPort);
		~SecureSmtpClientBase();
		SecureSmtpClientBase(const SecureSmtpClientBase& other); //Copy constructor
        SecureSmtpClientBase& operator=(const SecureSmtpClientBase& other); //Copy assignment
		SecureSmtpClientBase(SecureSmtpClientBase&& other) noexcept; //Move constructor
		SecureSmtpClientBase& operator=(SecureSmtpClientBase&& other) noexcept; //Move assignement
	protected:
    	//Attributes used to communicate with the server
		BIO *mBIO;
		SSL_CTX *mCTX;
		SSL *mSSL;
		//Methods
		void cleanup() override;
		//Methods used to establish the connection with server
		int getServerSecureIdentification();
		int startTLSNegotiation();
		void initializeSSLContext();
		//Methods to send commands to the server
		int sendCommand(const char *pCommand, int pErrorCode) override;
		int sendCommandWithFeedback(const char *pCommand, int pErrorCode, int pTimeoutCode) override;
    };
} // namespace jed_utils

#endif