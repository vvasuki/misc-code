const lib = require('lib')({token: process.env.STDLIB_SECRET_TOKEN});

// Be sure to add a slash command with a "user" option at https://autocode.com/tools/discord/command-builder/
// console.log(context.params.event.data);
let userID = context.params.event.data.options[0].value;

let retrieve = await lib.discord.guilds['@0.1.0'].members.retrieve({
  user_id: userID,
  guild_id: context.params.event.guild_id
});

let username = `${retrieve.user.username}#${retrieve.user.discriminator}`

let key = `${context.params.event.guild_id}_${userID}`

let last_status = await lib.utils.kv['@0.1.16'].get({
  key: key,
});

if(last_status === 'online') {
  await lib.discord.channels['@0.2.0'].messages.create({
    channel_id: context.params.event.channel_id,
    content: `<@!${context.params.event.member.user.id}>`,
    embed: {
      description: `**${username}** is online now!`
    }
  });
}
else if(last_status === null) {
  await lib.discord.channels['@0.2.0'].messages.create({
    channel_id: context.params.event.channel_id,
    content: `<@!${context.params.event.member.user.id}>`,
    embed: {
      description: `Hmm, I don't have any info for that user`
    }
  });
}
else {
  var d = new Date(parseInt(last_status)*1000);
  let time_stamp = d.toLocaleString('en-CA', {timeZone: 'Asia/Kolkata', hour12: false});
  await lib.discord.channels['@0.2.0'].messages.create({
    channel_id: context.params.event.channel_id,
    content: `<@!${context.params.event.member.user.id}>`,
    embed: {
      description: `**${username}** - ${time_stamp} IST.`
    }
  });
}
