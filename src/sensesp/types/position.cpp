#include <sensesp/types/position.h>

namespace sensesp {

/**
 * @brief Adds support in ArduinoJson to deserialize Position type data.
 *
 * This is an ArduinoJson custom converter to convert position type data from
 * JSON into a Postion struct. The JSON data must at least contain "latitude"
 * and "longitude", "altitude" is optional. ArduinoJson will automatically
 * call this function whenever it has to convert a JSON to a Position struct.
 * More info here: https://arduinojson.org/news/2021/05/04/version-6-18-0/
 *
 * @param src The JSON document containing the position data
 * @param dst The address to a Position struct to write the data to
 */
void convertFromJson(JsonVariantConst src, Position &dst) {
  dst.longitude = src["longitude"].as<double>();
  dst.latitude = src["latitude"].as<double>();

  if (src.containsKey("altitude")) {
    dst.altitude = src["altitude"].as<float>();
  }
}

/**
 * @brief Tells ArduinoJson whether the given JSON is a Position or not
 *
 * This function is automatically called by ArduinoJson whenever it has to
 * convert a JSON to a Position struct.
 *
 * @param src A JSON document
 * @return true if the given JSON contains "latitude" and "longitude" keys
 * @return false if the given JSON doesn't contain "latitude" or "longitude"
 * keys
 */
bool canConvertFromJson(JsonVariantConst src, const Position &) {
  return src.containsKey("latitude") && src.containsKey("longitude");
}

}  // namespace sensesp
