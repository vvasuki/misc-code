const lib = require('lib')({token: process.env.STDLIB_SECRET_TOKEN});

if (!context.params.event.content.startsWith(`!last-online`)) return;

let userID = context.params.event.content.split(` `).slice(1).toString()

if(!userID) {
  await lib.discord.channels['@0.2.0'].messages.create({
    channel_id: context.params.event.channel_id,
    content: `<@!${userID}>`,
    embed: {
      description: `You did not mention the user to check!`
    }
  });
  return
}

userID = userID.replace(/\D/g,'');

let retrieve = await lib.discord.guilds['@0.1.0'].members.retrieve({
  user_id: `<@!${userID}>`,
  guild_id: context.params.event.guild_id
});

let username = `${retrieve.user.username}#${retrieve.user.discriminator}`

let key = `${context.params.event.guild_id}_${userID}`

let last_status = await lib.utils.kv['@0.1.16'].get({
  key,
});

if(last_status === 'online') {
  await lib.discord.channels['@0.2.0'].messages.create({
    channel_id: context.params.event.channel_id,
    content: `<@!${context.params.event.author.id}>`,
    embed: {
      description: `**${username}** is online now!`
    }
  });
}
else if(last_status === null) {
  await lib.discord.channels['@0.2.0'].messages.create({
    channel_id: context.params.event.channel_id,
    content: `<@!${context.params.event.author.id}>`,
    embed: {
      description: `Hmm, I don't have any info for that user`
    }
  });
}
else {
  await lib.discord.channels['@0.2.0'].messages.create({
    channel_id: context.params.event.channel_id,
    content: `<@!${context.params.event.author.id}>`,
    embed: {
      description: `**${username}** was last online  <t:${last_status}>`
    }
  });
}
