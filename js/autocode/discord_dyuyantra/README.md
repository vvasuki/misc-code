# Discord member "last online for all users" command

Retrieve info on when user(s) were last online

## Setup
It uses slash commands AND prefix commands. You can use either. Prefix commands require no setup

### Slash command setup

- Go to https://autocode.com/tools/discord/command-builder/
- Link your bot using **Link Account**
- Set a slash command called **lastall**


### Bot permissions

Your bot also needs **Presence Intent** enabled to detect users presence changes

You can do this by going to: 
https://discord.com/developers/applications -> [Your bot] -> Bot -> Privileged Gateway Intents -> **Enable Presence Intent**


## Usage
### Slash command use

- Type `/lastall` into your server. You should get a response such as the below:

```
Online: vih#1233
Online: skktl#1845
Online: ak#8502
Online: Ki#2258
2022-09-13, 12:57:47: राजेश्व#7749
2022-09-13, 12:46:24: krsree#912
```

- Type `/laston` into your server, and the command should come up.
- Enter in the user you want to check in the option box

### Prefix command use

`!laston [@mention]` - Example usage `!laston @randomguy400`


