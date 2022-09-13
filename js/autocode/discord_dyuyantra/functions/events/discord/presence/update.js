const lib = require('lib')({token: process.env.STDLIB_SECRET_TOKEN});

let key = `${context.params.event.guild_id}_${context.params.event.user.id}`;

console.log(context.params.event.user.id)
console.log(context.params.event.status)

let last_status = await lib.utils.kv['@0.1.16'].get({
  key: key,
});

if(context.params.event.status === 'online' || context.params.event.status === 'dnd' || context.params.event.status === 'idle'){
  
  if (last_status === 'online') return;
  
  await lib.utils.kv['@0.1.16'].set({
    key: key,
    value: `online`
  });
}
else if(context.params.event.status === 'offline'){
  
  if (last_status === 'offline') return;
  
    await lib.utils.kv['@0.1.16'].set({
      key: key,
      value: Math.round(new Date().getTime() / 1000)
    });
}