# Interface graphique de contrôle

```
odin-gui unix /tmp/ecran.sock [debug]
```

## Messages JSON

### Récupérer la configuration

* Query
```json
{
    "action": "GET_CONFIG"
}
```

* Réponse
```json
{
    "status": "OK",
    "action": "GET_CONFIG",
    "data": {
        "team": "JAUNE",
        "startCalibration": false,
        "strategy": "STRAT1",
        "modeManuel": false,
        "skipCalageBordure": false
    }
}
```

### Mettre à jour les informations d'init

* Query
```json
{
    "action": "UPDATE_STATE",
    "data": {
        "i2c": true,
        "lidar": true,
        "au": true,
        "alim12v": true,
        "alim5vp": true,
        "tirette": true,
        "otherRobot": true,
        "message": "Démarrage"
    }
}
```

* Réponse
```json
{
    "status": "OK",
    "action": "UPDATE_STATE"
}
```

### Mettre à jour les informations de match

* Query
```json
{
    "action": "UPDATE_MATCH",
    "data": {
        "score": 90,
        "message": "Fin de match"
    }
}
```

* Réponse
```json
{
    "status": "OK",
    "action": "UPDATE_MATCH"
}
```
