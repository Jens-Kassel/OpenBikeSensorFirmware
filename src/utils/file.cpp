/*
 * Copyright (C) 2019-2021 OpenBikeSensor Contributors
 * Contact: https://openbikesensor.org
 *
 * This file is part of the OpenBikeSensor firmware.
 *
 * The OpenBikeSensor firmware is free software: you can
 * redistribute it and/or modify it under the terms of the GNU
 * Lesser General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * OpenBikeSensor firmware is distributed in the hope that
 * it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with the OpenBikeSensor firmware.  If not,
 * see <http://www.gnu.org/licenses/>.
 */

#include "file.h"

bool FileUtil::appendFile(fs::FS &fs, const char * path, const char * message) {
  bool result = false;
  log_i("Appending to file: %s", path);

  File file = fs.open(path, FILE_APPEND);
  if (!file) {
    log_e("Failed to open file for appending");
    return false;
  }
  if (file.print(message)) {
    result = true;
  } else {
    log_e("Append failed");
  }
  file.close();
  return result;
}
