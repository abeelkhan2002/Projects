// Satellite Assignment
// 2023/9/22
// Abeel Khan 
// C++ Program that operates a satellite

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdint>

using namespace std;

// Defining shorthand names for various elements 
#define GroundStationOutputChannel cout
#define masterInfoSatellite masterInfoDiscriminatedUnionStruct.masterUnion.satelliteInformation
#define masterInfoExperiment masterInfoDiscriminatedUnionStruct.masterUnion.expirimentInformation
#define infoStoredArrayatindexSatellite infoStoredArray[index].masterUnion.satelliteInformation
#define infoStoredArrayatindexExperiment infoStoredArray[index].masterUnion.expirimentInformation

const string TELEMETRY_INPUT_CHANNEL = "inputTelemetryData.txt";

enum class MESSAGE_ID_ENUM_CLASS { SATELLITE_INFORMATION_MESSAGE = 1, EXPERIMENT_INFORMATION_MESSAGE = 2 };
MESSAGE_ID_ENUM_CLASS messageIdEnum;

enum class INFO_TYPE_ENUM_CLASS { SATELLITE_INFORMATION, EXPERIMENT_INFORMATION, EMPTY };
const uint8_t ARRAY_DATA_STORAGE_SIZE = 5;

float_t minTemperature = 212,       // -50 - 212
maxTemperature = -50;
float_t minVoltage = 100.0,          // 0.0 - 100.0
maxVoltage = 0.0;

struct SatelliteInfoStruct {
    float_t temperature;
    float_t voltage;
};
struct ExperimentInfoStruct {
    uint16_t radiationCount;
    uint16_t latchupEventsCount;
};
union MasterUnion {
    SatelliteInfoStruct  satelliteInformation;
    ExperimentInfoStruct expirimentInformation;
};

// Discriminated Union
struct MasterInfoDiscriminatedUnionStruct {
    INFO_TYPE_ENUM_CLASS infoTypeEnum;
    MasterUnion          masterUnion;
};

// Void function to display all information 
void displayTelemetryInfo(const MasterInfoDiscriminatedUnionStruct& info, const MasterInfoDiscriminatedUnionStruct infoStoredArray[]) {
    GroundStationOutputChannel << "Current Telemetry Information:" << endl;
    GroundStationOutputChannel << "----------------------------" << endl;

    switch (info.infoTypeEnum) {
    case INFO_TYPE_ENUM_CLASS::SATELLITE_INFORMATION:
        GroundStationOutputChannel << "Temperature : " << info.masterUnion.satelliteInformation.temperature << endl;
        GroundStationOutputChannel << "Voltage : " << info.masterUnion.satelliteInformation.voltage << endl;
        break;
    case INFO_TYPE_ENUM_CLASS::EXPERIMENT_INFORMATION:
        GroundStationOutputChannel << "Radiation Count : " << info.masterUnion.expirimentInformation.radiationCount << endl;
        GroundStationOutputChannel << "Latch Up Events : " << info.masterUnion.expirimentInformation.latchupEventsCount << endl;
        break;
    default:
        break;
    }

    GroundStationOutputChannel << "History:" << endl;
    GroundStationOutputChannel << "--------" << endl;

    // for loop that reapeats temperature and voltage 

    for (uint8_t index = 0; index < ARRAY_DATA_STORAGE_SIZE; index++) {
        switch (infoStoredArray[index].infoTypeEnum) {
        case INFO_TYPE_ENUM_CLASS::SATELLITE_INFORMATION:
            GroundStationOutputChannel << "Temperature : " << infoStoredArray[index].masterUnion.satelliteInformation.temperature << endl;
            GroundStationOutputChannel << "Voltage : " << infoStoredArray[index].masterUnion.satelliteInformation.voltage << endl;
            break;
        case INFO_TYPE_ENUM_CLASS::EXPERIMENT_INFORMATION:
            GroundStationOutputChannel << "Radiation Count : " << infoStoredArray[index].masterUnion.expirimentInformation.radiationCount << endl;
            GroundStationOutputChannel << "Latch Up Events : " << infoStoredArray[index].masterUnion.expirimentInformation.latchupEventsCount << endl;
            break;
        default:
            break;
        }
    }

    GroundStationOutputChannel << "Summary Information" << endl;
    GroundStationOutputChannel << "-------------------" << endl;

    uint16_t totalRadiationCount = 0, totalLatchupEventCount = 0, infoSICount = 0, infoEICount = 0;

    //This code iterates through an array of telemetry data, categorizes each entry as either satellite or experiment information
    for (uint8_t index = 0; index < ARRAY_DATA_STORAGE_SIZE; index++) {
        switch (infoStoredArray[index].infoTypeEnum) {
        case INFO_TYPE_ENUM_CLASS::SATELLITE_INFORMATION:
            infoSICount++;
            minTemperature = min(minTemperature, infoStoredArray[index].masterUnion.satelliteInformation.temperature);
            maxTemperature = max(maxTemperature, infoStoredArray[index].masterUnion.satelliteInformation.temperature);
            minVoltage = min(minVoltage, infoStoredArray[index].masterUnion.satelliteInformation.voltage);
            maxVoltage = max(maxVoltage, infoStoredArray[index].masterUnion.satelliteInformation.voltage);
            break;
        case INFO_TYPE_ENUM_CLASS::EXPERIMENT_INFORMATION:
            infoEICount++;
            totalRadiationCount += infoStoredArray[index].masterUnion.expirimentInformation.radiationCount;
            totalLatchupEventCount += infoStoredArray[index].masterUnion.expirimentInformation.latchupEventsCount;
            break;
        default:
            break;
        }
    }
    // Printing summary information related to the telemetry data processing to the output stream
    GroundStationOutputChannel << "Number of Satellite Information Records: " << infoSICount << endl;
    GroundStationOutputChannel << "Number of Experiment Information Records: " << infoEICount << endl;
    GroundStationOutputChannel << "Total Radiation Count : " << totalRadiationCount << endl;
    GroundStationOutputChannel << "Total Latch Up Event Count : " << totalLatchupEventCount << endl;
    GroundStationOutputChannel << "Maximum Temperature : " << maxTemperature << endl;
    GroundStationOutputChannel << "Minimum Temperature : " << minTemperature << endl;
    GroundStationOutputChannel << "Maximum Voltage : " << maxVoltage << endl;
    GroundStationOutputChannel << "Minimum Voltage : " << minVoltage << endl;

    GroundStationOutputChannel << "Press the enter key once or twice to continue..." << endl;
    cin.ignore();
    cin.get();
}

int main()
{
    //These lines of code declare an array to store telemetry data, initialize an index variable to keep track of the array's current position
    MasterInfoDiscriminatedUnionStruct infoStoredArray[ARRAY_DATA_STORAGE_SIZE];
    uint8_t entryPositionIndex = 0;
    MasterInfoDiscriminatedUnionStruct masterInfoDiscriminatedUnionStruct;

    ifstream telemetryInputChannel(TELEMETRY_INPUT_CHANNEL);
    if (!telemetryInputChannel.is_open()) {
        cout << "Failed to open input file." << endl;
        return EXIT_FAILURE;
    }

    GroundStationOutputChannel << setprecision(1) << fixed << showpoint;

    //These lines of code read message IDs from an input channel and then determine the type of telemetry data
    uint16_t messageIdUInt;
    while (telemetryInputChannel >> messageIdUInt) {
        switch (messageIdUInt) {
        case 1:
            masterInfoDiscriminatedUnionStruct.infoTypeEnum = INFO_TYPE_ENUM_CLASS::SATELLITE_INFORMATION;
            telemetryInputChannel >> masterInfoSatellite.temperature >> masterInfoSatellite.voltage;
            break;
        case 2:
            masterInfoDiscriminatedUnionStruct.infoTypeEnum = INFO_TYPE_ENUM_CLASS::EXPERIMENT_INFORMATION;
            telemetryInputChannel >> masterInfoExperiment.radiationCount >> masterInfoExperiment.latchupEventsCount;
            break;
        default:
            break;
        }

        infoStoredArray[entryPositionIndex] = masterInfoDiscriminatedUnionStruct;
        entryPositionIndex = (entryPositionIndex + 1) % ARRAY_DATA_STORAGE_SIZE;

        displayTelemetryInfo(masterInfoDiscriminatedUnionStruct, infoStoredArray);
    }

    GroundStationOutputChannel << "Program Done" << endl;

    return EXIT_SUCCESS;
}
