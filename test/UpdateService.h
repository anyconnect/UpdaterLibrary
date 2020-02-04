#ifndef _UPDATE_SERVICE_H_
#define _UPDATE_SERVICE_H_

#include <map>
#include <string>
#include <vector>
#include <functional>

namespace com {
namespace anyconnect {
namespace update {

///
/// \brief Update status.
///
///
enum class UpdateStatus {
  SUCCESS,
  INPROGRESS,
  INTERRUPTED,
  INTEGRITY_FAIL,
  REBOOT_REQUIRES,
  FAIL
};


///
/// \brief Update priority.
///
///
enum class UpdatePriority {
  RECOMMENDED,
  MANDATORY,
  UNRECOGNIZED
};


///
/// \brief structure for authentication
/// credentials for the download URL.
///

struct credential {
  std::string username;
  std::string password;
  std::string token;
};

///
/// Data structure to provide user's custom data in key-value form.
///
typedef std::map<std::string, std::string> Userdata;

///
/// Handler for update status.
///
/// \param[out] version - version of the requested update.
/// \param[out] url - URL of the downloadable package.
/// \param[out] UpdateStatus - status of the requested update.
///
typedef std::function<void(std::string version, std::string url, UpdateStatus status)> UpdateStatusHandler;

class UpdateService{
public:
  UpdateService()
  {
    ;
  }

  ///
  /// Returns true if the firmware or package update requires.
  ///
  /// \param[in] packageName - name of the downloadable package/firmware.
  /// \param[in] packageVersion - version of the downloadable package/firmware.
  /// \param[in] installedVersion - version of the currently installed package/firmware.
  /// \param[in] updatePriority - priority of the update (RECOMMENDED, MANDATORY, UNRECOGNIZED).
  /// \param[in] userdata - Additional userdata required to check update requirememt.
  /// \param[out] TRUE/FALSE - true if update requires, otherwise false.
  ///
  virtual bool checkUpdateRequirement(const std::string packageName, const std::string packageVersion, const std::string installedVersion, UpdatePriority updatePriority, const Userdata& userdata) = 0;

  ///
  /// Set a callback for receiving status of the requested update.
  ///
  /// \param[in] UpdateStatusHandler - Handler function for the update status.
  ///
  virtual void setUpdateStatusCallback(UpdateStatusHandler handler) = 0;

  ///
  /// Download package/firmware and updates.
  ///
  /// \param[in] packageName - name of the downloadable package/firmware.
  /// \param[in] packageVersion - version of the downloadable package/firmware.
  /// \param[in] url - URL of the downloadable package/firmware.
  /// \param[in] cred - credential of the URL access(if any).
  ///
  virtual void update(const std::string packageName, const std::string packageVersion, const std::string url, credential cred) = 0;


  ~UpdateService()
  {
    ;
  }
};

}
}
}
#endif
