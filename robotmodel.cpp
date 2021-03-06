#include "robotmodel.h"
#include "common.h"

RobotModel* RobotModel::instance = nullptr;

RobotModel* RobotModel::getInstance() {
    if (instance == nullptr) {
        instance = new RobotModel();
    }
    return instance;
}

QObject* RobotModel::singletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(scriptEngine)

    auto instance = RobotModel::getInstance();
    engine->setObjectOwnership(instance, QQmlEngine::CppOwnership);
    return instance;
}

RobotModel::RobotModel(QObject *parent) : QObject(parent) {
    // RW
    this->setExit(false);
    this->setTeam(UNKNOWN);
    this->setStrategy(BASIC);
    this->setStartCalibration(false);
    this->setModeManuel(false);
    this->setSafeAvoidance(true);
    this->setDeposePartielle(false);
    this->setEchangeEcueil(false);
    this->setSkipCalageBordure(false);
    this->setTwoRobots(false);

    // RO
    this->setScore(0);
    this->setI2c(false);
    this->setLidar(false);
    this->setInMatch(false);
    this->setAu(false);
    this->setAlim12v(false);
    this->setAlim5vp(false);
    this->setTirette(false);
    this->setOtherRobot(false);
    this->setBalise(false);
    this->setMessage("Démarrage en cours ...");
}

// QML RW data //
// ----------- //

bool RobotModel::getExit() {
    return this->exit;
}
void RobotModel::setExit(bool exit) {
    this->exit = exit;
    emit exitChanged(exit);
}

RobotModel::Team RobotModel::getTeam() {
    return this->team;
}
void RobotModel::setTeam(Team team) {
    this->team = team;
    emit teamChanged(team);
}

bool RobotModel::getStartCalibration() {
    return this->startCalibration;
}
void RobotModel::setStartCalibration(bool value) {
    this->startCalibration = value;
    emit startCalibrationChanged(value);
}

RobotModel::Strategy RobotModel::getStrategy() {
    return this->strategy;
}
void RobotModel::setStrategy(Strategy strategy) {
    this->strategy = strategy;
    emit strategyChanged(strategy);
}

bool RobotModel::getSkipCalageBordure() {
    return this->skipCalageBordure;
}
void RobotModel::setSkipCalageBordure(bool value) {
    this->skipCalageBordure = value;
    emit skipCalageBordureChanged(value);
}

bool RobotModel::getModeManuel() {
    return this->modeManuel;
}
void RobotModel::setModeManuel(bool value) {
    this->modeManuel = value;
    emit modeManuelChanged(value);
}

bool RobotModel::getSafeAvoidance() {
    return this->safeAvoidance;
}
void RobotModel::setSafeAvoidance(bool value) {
    this->safeAvoidance = value;
    emit safeAvoidanceChanged(value);
}

bool RobotModel::getDeposePartielle() {
    return this->deposePartielle;
}
void RobotModel::setDeposePartielle(bool value) {
    this->deposePartielle = value;
    emit deposePartielleChanged(value);
}

bool RobotModel::getEchangeEcueil() {
    return this->echangeEcueil;
}
void RobotModel::setEchangeEcueil(bool value) {
    this->echangeEcueil = value;
    emit echangeEcueilChanged(value);
}

bool RobotModel::getTwoRobots() {
    return this->twoRobots;
}
void RobotModel::setTwoRobots(bool value) {
    this->twoRobots = value;
    emit twoRobotsChanged(value);
}

// QML RO data //
// ----------- //

bool RobotModel::getInMatch() {
   return this->inMatch;
}
void RobotModel::setInMatch(bool value) {
    this->inMatch = value;
    emit inMatchChanged(value);
}

bool RobotModel::getI2c() {
    return this->i2c;
}
void RobotModel::setI2c(bool value) {
    this->i2c = value;
    emit i2cChanged(value);
}

bool RobotModel::getLidar() {
    return this->lidar;
}
void RobotModel::setLidar(bool value) {
    this->lidar = value;
    emit lidarChanged(value);
}

bool RobotModel::getAu() {
    return this->au;
}
void RobotModel::setAu(bool value) {
    this->au = value;
    emit auChanged(value);
}

bool RobotModel::getAlim12v(){
    return this->alim12v;
}
void RobotModel::setAlim12v(bool value){
    this->alim12v = value;
    emit alim12vChanged(value);
}

bool RobotModel::getAlim5vp(){
    return this->alim5vp;
}
void RobotModel::setAlim5vp(bool value){
    this->alim5vp = value;
    emit alim5vpChanged(value);
}

bool RobotModel::getTirette() {
    return this->tirette;
}
void RobotModel::setTirette(bool value) {
    this->tirette = value;
    emit tiretteChanged(value);
}

bool RobotModel::getOtherRobot() {
    return this->otherRobot;
}
void RobotModel::setOtherRobot(bool value) {
    this->otherRobot = value;
    emit otherRobotChanged(value);
}

bool RobotModel::getBalise() {
    return this->balise;
}
void RobotModel::setBalise(bool value) {
    this->balise = value;
    emit baliseChanged(value);
}

int RobotModel::getScore(){
    return this->score;
}
void RobotModel::setScore(int value){
    this->score = value;
    emit scoreChanged(value);
}

QString RobotModel::getMessage() {
    return this->message;
}
void RobotModel::setMessage(QString value) {
    this->message = value;
    emit messageChanged(value);
}
